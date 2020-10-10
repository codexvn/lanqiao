/*
这种写法还是有一定的问题，因为题目给定的范围是（6≤N≤40，1≤K≤6）
所以考虑极值的话N=40、K=1，不使用字符串来保存数据的话只有在64位操作系统中使用double类型才能把数据完整的保存下来  
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
string digital_list;
double FindMax(int x,int y,vector<vector<double> >&dp){
	if(x==y)
		return dp[x-1][y-1]*(digital_list[x]-'0');
	else{
		double tmp_max=0,tmp_atof;
		for(int i=0;i<y;i++){
			string tmp=string(digital_list.begin()+i+1,digital_list.begin()+y+1);
			tmp_atof=dp[x-1][i]*atof(tmp.c_str());
			if(tmp_atof>tmp_max)
				tmp_max=tmp_atof;
		}
		return tmp_max;
	}
	
}
int main(){

	int N,K;
	cin>>N>>K>>digital_list;
	vector<vector<double> >dp(K+1,vector<double>(N));  //double保证最后的结果不会越界
	dp[0][0]=digital_list[0]-'0';
	for(int i=1;i<N;i++)
		dp[0][i]=dp[0][i-1]*10+(digital_list[i]-'0');
	for(int i=1;i<K+1;i++)
		for(int j=i;j<N;j++)
			dp[i][j]=FindMax(i,j,dp);
	cout<<fixed<<setprecision(0);
		cout<<dp[K][N-1]<<endl;
	return 0;
}
