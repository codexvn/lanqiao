#include<iostream>
#include<cstdlib>
using namespace std;
int data[9][9]={0},book[9][9]={0},flag[2][9][2],count=0;
inline void BlackDFS(int step,int n,int i,int j);
inline void DFS(int step,int n,int i,int j);
bool FlagCheck(int n,int flag[9][2])
{
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(flag[i][0] == flag[j][0] \ 
			 or flag[i][1] == flag[j][1]\
			 or abs(flag[i][0]-flag[j][0])== abs(flag[i][1]-flag[j][1]) 
			 ) 
			 	return false;
	
	return true;
					 	
}
inline void DFS(int step,int n,int i,int j)
{
	if(step>n){
		if(FlagCheck(n,flag[0])){
			BlackDFS(1,n,1,1);
			return;
		}
	}
	 else 
		for(;i<=n;i++,j=0)
			for(;j<=n;j++){
				if(data[i][j]==1 and book[i][j] != 1){
					book[i][j]=1;
					flag[0][step][0]=i; 	
					flag[0][step][1]=j; 	
					DFS(step+1,n,i,j);
					book[i][j]=0;
				} else
					continue;
		}	
}
inline void BlackDFS(int step,int n,int i,int j)
{
	if(step>n){
		if(FlagCheck(n,flag[1])){
			count++;
			return;
		}
	}
	 else 
		for(;i<=n;i++,j=0)
			for(;j<=n;j++){
				if(data[i][j]==1 and book[i][j] != 1){
					book[i][j]=1;
					flag[1][step][0]=i; 	
					flag[1][step][1]=j; 	
					BlackDFS(step+1,n,i,j);
					book[i][j]=0;
				} else
					continue;
		}	
}
int main (){

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
				cin>>data[i][j];
			}
	DFS(1,n,1,1);
	//for(int i=n;i>=1;i--)count/=i;
//	for(int i=n;i>=1;i--)count/=i;
	cout << count;
}

