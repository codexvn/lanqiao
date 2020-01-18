#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;   //本题对 π的要求很精确，可以使用数学公式求 
/*	
tan(π/4)=1
所以 π/4=atan(1)
π=atan(1)*4
*/ 
int main()
{
	double N,pai=atan(1)*4;
	cin>>N;
	printf("%.7f",pai*N*N);
}
