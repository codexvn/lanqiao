#include<iostream>
using namespace std;
int main()
{
	string date;
	int length,end,count=0;
	bool flag=false; //�ж��ǲ����Ѿ����ڵ�������ĸ 
	cin>>length>>date;
	end=length-1;
	for(int i=0;i<end;i++)
	{
		int j;
		for(j=end;j>i;j--){
			if(date[i]==date[j]){
				for(int k=j;k<end;k++) //������������ 
					{
						swap(date[k],date[k+1]);
						count++;
					}
				break;

			}
			
		}	
		if(j==i)   //�ж��Ƿ���Թ��ɻ��� 
		{
			if(length%2==0 or flag==true){
				cout<<"Impossible"<<endl;
				return 0;
			} else {
				flag=true;   
				count+=(length/2-i);   //�����������������ĸ���м���ĸ��ֱ������ 
			}

		} else end--;
	}
	cout<<count;
	return 0;
}

