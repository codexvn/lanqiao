#include<iostream>
using namespace std;
int main()
{
	int n,max,min,sum,get;
	cin>>n;
	cin>>sum;
	min=sum;
	max=sum;
	n--;
	while(n--)
	{
		cin>>get;
		if(get>max)max=get;
		else if(get<min)min=get;
		sum+=get;
	}
	cout<<max<<endl<<min<<endl<<sum<<endl;
}
