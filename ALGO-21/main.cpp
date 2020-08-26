#include<iostream>
using namespace std;
int main(void){
	int V,n;
	cin>>V>>n;
	int data,dp[20001];
	for (int i=0;i<n;++i){
		cin>>data;
		for(int j=V;j>=data;--j){
			dp[j]=max(dp[j],dp[j-data]+data);
		}
	}
	cout<<V-dp[V];
} 
