#include<iostream>
using namespace std;
void FJ(int n)
{
	if(n==1)
		cout<<'A';
	else {
		FJ(n-1);
		cout<<char(n+'A'-1);
		FJ(n-1);
	}
	
}
int main()
{
	
	int n;
	cin>>n;
	FJ(n);
	return 0;
}
