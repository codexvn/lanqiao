#include<iostream>
using namespace std;
int main()
{
	int n;
	int yan_hui[34][35]={0,1};
	cin>>n;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=i+1;j++)
		yan_hui[i][j]=yan_hui[i-1][j-1]+yan_hui[i-1][j];
	}
	for (int i=0;i<n;i++)
		{
			cout<<yan_hui[i][1];
		for (int j=2;j<=i+1;j++)
			cout<<' '<<yan_hui[i][j];
		cout<<endl;
	}return 0;
} 
 
