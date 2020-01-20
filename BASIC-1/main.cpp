#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	if(N%400==0 or (N%4==0 and N%100!=0))
		cout<<"yes"<<endl;
	else 
		cout<< "no"<<endl;
	
	return 0;
}
