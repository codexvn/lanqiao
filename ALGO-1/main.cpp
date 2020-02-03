#include<iostream>
#include<iterator>
#include<set>
using namespace std;
int main()
{
	multiset<int>sorted;
	int n,m,i,r,k;
	cin>>n;
	int *data=new int[n];
	for(int l=0;l<n;l++)
		cin>>data[l];
	cin>>m;
	for(int l=0;l<m;l++){
		cin>>i>>r>>k;
		sorted.clear();
		for(int o=i-1;o<r;o++){
			sorted.insert(data[o]);
		}
		multiset<int>::reverse_iterator flag=sorted.rbegin();
		advance(flag,k-1);
		cout<<*flag<<endl;
	}	 
}
