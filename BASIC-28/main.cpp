#include<iostream>
#include<set>
using namespace std;
int main()
{
	multiset<int>data;
	int n,get,count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>get;
		data.insert(get);
	}
	while(data.size()!=1){
		int tmp=*data.begin();
		data.erase(data.begin());
		tmp+=*data.begin();
		data.erase(data.begin());
		data.insert(tmp);
		count +=tmp;
	}
	cout<<count;
}
