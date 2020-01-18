#include<iostream>
using namespace std;
int F[1000001]={0,1,1};
int main(void)
{
	int N;
	for(int i=3;i<=1000001;i++)F[i]=(F[i-1]+F[i-2])%10007;  //提前将结果算出然后调用比接受数据之后再计算结果要快得多 
	cin>>N;
	cout <<F[N];
}
