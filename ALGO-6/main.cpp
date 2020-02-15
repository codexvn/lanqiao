#include<iostream>
#include<set>
struct Node{
	int begin,end,value;
	friend bool operator < (const Node& a,const Node&b){
		return a.value<b.value;
	}
};
int father[10001]={0};
inline int GetFather(int n){
	if(father[n]==n)
		return n;
	else
		return GetFather(father[n]);
}

using namespace std;
int main(){
	int N,P;
	int count=0,min=9999999;
	multiset<Node>side_value;
	cin>>N>>P;
	int node_value[10001]={0};
	for(int i=1;i<=N;i++){
		cin>>node_value[i];
		father[i]=i;
		if(min>node_value[i])
			min=node_value[i];
	}
	Node tmp;
	for(int i=1;i<=P;i++){
		cin>>tmp.begin>>tmp.end>>tmp.value;
		tmp.value=tmp.value*2+node_value[tmp.begin]+node_value[tmp.end];
		side_value.insert(tmp);
	}
	for(multiset<Node>::iterator i=side_value.begin();i!=side_value.end();i++)
		{
			int begin_father=GetFather((*i).begin),end_father=GetFather((*i).end);	
				if(begin_father!=end_father){
					father[(*i).end]=(*i).begin;
					count+=(*i).value;
				}
		}
	count+=min;
	cout<<count;
	return 0;
}
