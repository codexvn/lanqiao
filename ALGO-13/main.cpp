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
	data[0].push_back(tmp);//���յ�һ����ֵ 
	while(cin>>tmp){
		vector<vector<int> >::iterator i=lower_bound(data.begin(),data.end(),tmp,cmp);
		if(i==data.end()) //��ǰֵ�������Ѿ�ʹ�ù���ϵͳ����������һ���µ�ϵͳ 
			data.push_back(vector<int>(){tmp});
		else i->push_back(tmp);
	}
	cout<<data.size()<<endl<<data.back().back();
	return 0;
}
