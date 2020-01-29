#include<iostream>
using namespace std;
int main()
{
	string date;
	int length,end,count=0;
	bool flag=false; //判断是不是已经存在单个的字母 
	cin>>length>>date;
	end=length-1;
	for(int i=0;i<end;i++)
	{
		int j;
		for(j=end;j>i;j--){
			if(date[i]==date[j]){
				for(int k=j;k<end;k++) //交换相邻数据 
					{
						swap(date[k],date[k+1]);
						count++;
					}
				break;

			}
			
		}	
		if(j==i)   //判断是否可以构成回文 
		{
			if(length%2==0 or flag==true){
				cout<<"Impossible"<<endl;
				return 0;
			} else {
				flag=true;   
				count+=(length/2-i);   //假设这个单数个的字母是中间字母，直接跳过 
			}

		} else end--;
	}
	cout<<count;
	return 0;
}

