#include<iostream>
using namespace std;
int main()
{
	int n,data[1000],find,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>data[i];
	cin>>find;
	for(i=0;i<n;i++)
			if(data[i]==find)
				{
					cout<<i+1;
					return 0;
				}
	cout<<-1;
	return 0;
}
