#include<iostream>
#include<algorithm>
#define N 10
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n,a,b,c;
	int dp[2*N+1][N+1][N+1]={0},data[N+1][N+1]={0};//dp[���ǵڼ���][��һ�������ڵ�����][�ڶ��������ڵ�����]
													//��Ϊ��������ͬ�ģ����������ͬһ�У���2�����ߵ���ͬһ���ط� 
	cin>>n;
	while(true){   //�������� 
		cin>>a>>b>>c;
		if(a==0)
			break;
		data[a][b]=c;	
		}
	dp[1][1][1]=data[1][1];
	for(int foot = 2;foot<=2*n-1;++foot){ //���½ǣ�����Ҫ��2*n��
		 for(int x1=1;x1<=n && x1<=foot;++x1){ 
		 	for(int x2=1;x2<=n && x2<=foot;++x2){
		 		int y1=foot-x1+1,y2=foot-x2+1;
		 		if(x1==x2)//�ߵ���ͬһ���ط���ֻȡһ�νڵ��ֵ 
					dp[foot][x1][x2]=data[x1][y1];
				else
					dp[foot][x1][x2]=data[x1][y1]+data[x2][y2];
				
				dp[foot][x1][x2]+=max(max(dp[foot-1][x1-1][x2-1],dp[foot-1][x1-1][x2]),max(dp[foot-1][x1][x2-1],dp[foot-1][x1][x2]));
				  //dp[foot][x1][x2]��ʾ�ڵ�foot��ʱ2���˷ֱ��ߵ�[x1][foot-x1]��[x2][foot-x2]��ֵ֮�� 
		 	}
		 }
	}
	cout<<dp[2*n-1][n][n]; 
	return 0;
	
}
