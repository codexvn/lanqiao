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
 //��ǰоƬΪ��оƬʱ����Ϊ��оƬ���������ڻ�оƬ����������оƬ������в��Խ��Ϊ1����оƬ������в��Խ������Ϊ1����ǰоƬ��Ӧ����һ����1����Ŀһ������0����Ŀ 
 //��ǰоƬΪ��оƬʱ�� ��оƬ������в��Խ��Ϊ0�����Ե���һ�е�1֮��һ��С��2/n 
