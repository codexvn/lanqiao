#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;   //����� �е�Ҫ��ܾ�ȷ������ʹ����ѧ��ʽ�� 
/*	
tan(��/4)=1
���� ��/4=atan(1)
��=atan(1)*4
*/ 
int main()
{
	double N,pai=atan(1)*4;
	cin>>N;
	printf("%.7f",pai*N*N);
}
