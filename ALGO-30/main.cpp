#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int T,M,dp[1001]={0},time,value;
	cin>>T>>M;
	for(int i=0;i<M;++i){
		cin>>time>>value;
		for(int j =T;j>=time;--j){  //һ��Ҫ���򣬲�Ȼǰ������ݻ�Ӱ���������� 
			dp[j]=max(dp[j],dp[j-time]+value);
		}
	}
	 cout<<dp[T];
}
