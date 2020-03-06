#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	double x[4],y[4];
	cin>>x[0]>>y[0];
	cin>>x[1]>>y[1];
	cin>>x[2]>>y[2];	
	cin>>x[3]>>y[3];
	
	if( max(x[0],x[1]) <= min(x[2],x[3]) or \
		max(x[2],x[3]) <= min(x[0],x[1]) or \
		max(y[0],y[1]) <= min(y[2],y[3]) or \
		max(y[2],y[3]) <= min(y[0],y[1]) \
		 ) cout<<"0.00";
	else {
		std::sort(x,x+4);
		std::sort(y,y+4);
		printf("%.2lf",(x[2]-x[1])*(y[2]-y[1]));
	}
	return 0;
}
