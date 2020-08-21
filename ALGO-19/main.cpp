#include<iostream>
#include<algorithm>
#define N 10
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n,a,b,c;
	int dp[N+1][N+1][N+1][N+1]={0},data[N+1][N+1]={0};
	cin>>n;
	while(true){   //接收数据 
		cin>>a>>b>>c;
		if(a==0)
			break;
		data[a][b]=c;	
		}
	dp[1][1][1][1]=data[1][1];
	for(int x1 = 1;x1 <=n ;++x1){
		for (int y1=1;y1<=n;++y1){
			for(int x2=1;x2<=n;++x2){
				for(int y2=1;y2<=n;++y2){
					if(x1+y1!=x2+y2)
						continue;	//如果不是走了相同多的步数直接进入下一个循环
					dp[x1][y1][x2][y2]=max(max(dp[x1-1][y1][x2-1][y2],dp[x1-1][y1][x2][y2-1]),max(dp[x1][y1-1][x2-1][y2],dp[x1][y1-1][x2][y2-1])); 
					//dp[x1][y1][x2][y2]为即将到达[x1][y1]与即将到达[x2][y2]的上一步能取到的最优值之和 
					//[x1][y1]和[x2][y2]各自有2种状态 
					if(x1==x2 && y1==y2) //如果走到了一起则只取一次值
						dp[x1][y1][x2][y2]+=data[x1][y1];
					else
					dp[x1][y1][x2][y2]+=data[x1][y1]+data[x2][y2]; //否则加2个点的值 
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
	return 0;
	
}
