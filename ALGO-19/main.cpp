#include<iostream>
#include<algorithm>
#define N 10
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n,a,b,c;
	int dp[N+1][N+1][N+1][N+1]={0},data[N+1][N+1]={0};
	cin>>n;
	while(true){   //�������� 
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
						continue;	//�������������ͬ��Ĳ���ֱ�ӽ�����һ��ѭ��
					dp[x1][y1][x2][y2]=max(max(dp[x1-1][y1][x2-1][y2],dp[x1-1][y1][x2][y2-1]),max(dp[x1][y1-1][x2-1][y2],dp[x1][y1-1][x2][y2-1])); 
					//dp[x1][y1][x2][y2]Ϊ��������[x1][y1]�뼴������[x2][y2]����һ����ȡ��������ֵ֮�� 
					//[x1][y1]��[x2][y2]������2��״̬ 
					if(x1==x2 && y1==y2) //����ߵ���һ����ֻȡһ��ֵ
						dp[x1][y1][x2][y2]+=data[x1][y1];
					else
					dp[x1][y1][x2][y2]+=data[x1][y1]+data[x2][y2]; //�����2�����ֵ 
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
	return 0;
	
}
