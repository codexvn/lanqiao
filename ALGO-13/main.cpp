#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> a,int b){
	cout<<a.back()<<endl;
	return a.back()<=b;
}

int main(){
	vector<vector<int> >data(1);
	int tmp;
	cin>>tmp;
	data[0].push_back(tmp);//接收第一个数值 
	while(cin>>tmp){
		vector<vector<int> >::iterator i=lower_bound(data.begin(),data.end(),tmp,cmp);
		if(i==data.end()) //当前值不能用已经使用过的系统拦截则启用一套新的系统 
			data.push_back(vector<int>(){tmp});
		else i->push_back(tmp);
	}
	cout<<data.size()<<endl<<data.back().back();
	return 0;
}
