#include<iostream>
using namespace std;
int main()
{
	int H,M,S,time;
	cin>>time;
	H=time/3600;
	time%=3600;
	M=time/60;
	time%=60;
	S=time;
	cout<<H<<':'<<M<<':'<<S;
	return 0;
}
