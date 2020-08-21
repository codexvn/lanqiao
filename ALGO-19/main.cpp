#include<iostream>
#include<algorithm>
#define N 10
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n,a,b,c;
	int dp[2*N+1][N+1][N+1]={0},data[N+1][N+1]={0};//dp[这是第几步][第一个人所在的行数][第二个人所在的行数]
													//因为步数是相同的，所以如果在同一行，则2个人走到了同一个地方 
	cin>>n;
	while(true){   //接收数据 
		cin>>a>>b>>c;
		if(a==0)
			break;
		data[a][b]=c;	
		}
	dp[1][1][1]=data[1][1];
	for(int foot = 2;foot<=2*n-1;++foot){ //右下角，所以要走2*n步
		 for(int x1=1;x1<=n && x1<=foot;++x1){ 
		 	for(int x2=1;x2<=n && x2<=foot;++x2){
		 		int y1=foot-x1+1,y2=foot-x2+1;
		 		if(x1==x2)//走到了同一个地方则只取一次节点的值 
					dp[foot][x1][x2]=data[x1][y1];
				else
					dp[foot][x1][x2]=data[x1][y1]+data[x2][y2];
				
				dp[foot][x1][x2]+=max(max(dp[foot-1][x1-1][x2-1],dp[foot-1][x1-1][x2]),max(dp[foot-1][x1][x2-1],dp[foot-1][x1][x2]));
				  //dp[foot][x1][x2]表示在第foot步时2个人分别走到[x1][foot-x1]和[x2][foot-x2]的值之和 
		 	}
		 }
	}
	cout<<dp[2*n-1][n][n]; 
	return 0;
	
}
