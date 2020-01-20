#include<iostream>
using namespace std;
int N[5]={0};
void Print(int flag)
{
	
	if(flag==5)
	{
		for(int i=0;i<5;i++)cout<<N[i];
		cout<<endl;
		return ;
	} else
	{
		Print(flag+1);
		N[flag]=1;
		Print(flag+1);
		N[flag]=0;
	}
	
}
int main()
{
		Print(0);
	return 0;
}
