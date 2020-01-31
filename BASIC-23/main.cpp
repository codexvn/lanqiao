#include<iostream>
using namespace std;
int main()
{
	int date[2][21]={0},n;
	cin>>n;
 	for(int i=0;i<n;i++)
	 	for(int j=0;j<n;j++){
	 		cin>>date[0][j];
	 		if(date[0][j]==1)
			 	date[1][j]++;	 		
	 	}
	 for(int i=0,count=0;i<n;i++)   
	 	if(date[1][i]*2>n)
	 		{	
	 			cout<<i+1;
	 			count++;
	 			if(count>=1)
	 				cout<<' ';
	 		}
	return 0;
}
 //当前芯片为好芯片时，因为好芯片的数量大于坏芯片的数量，好芯片对其进行测试结果为1，坏芯片对其进行测试结果可能为1，则当前芯片对应的那一列中1的数目一定大于0的数目 
 //当前芯片为坏芯片时， 好芯片对其进行测试结果为0，所以当这一列的1之和一定小于2/n 
