#include<iostream>
using namespace std;
int F[1000001]={0,1,1};
int main(void)
{
	int N;
	for(int i=3;i<=1000001;i++)F[i]=(F[i-1]+F[i-2])%10007;  //��ǰ��������Ȼ����ñȽ�������֮���ټ�����Ҫ��ö� 
	cin>>N;
	cout <<F[N];
}
