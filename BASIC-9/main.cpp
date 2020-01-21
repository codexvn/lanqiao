#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>fore,five;
	for(int i=1;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				{
				if(2*(i+j)+k==n)
					fore.push_back(i*10001+j*1010+k*100);
				if(2*(i+j+k)==n)
					five.push_back(i*100001+j*10010+k*1100);
					}
	for(vector<int>::iterator start =fore.begin();start!=fore.end();start++ )
		cout<<*start<<endl;
	for(vector<int>::iterator start =five.begin();start!=five.end();start++ )
		cout<<*start<<endl;
}
