#include<iostream>
using namespace std;
int main()
{
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
			{
				int count =i*100+j*10+k,sum=i*i*i+j*j*j+k*k*k;
				if(count>99 and sum==count)
					cout <<sum<<endl;
			}
	return 0;
}
