#include<iostream>
using namespace std;
bool book[10];
int data[10],count;
void Dfs(int foot,int dst){
	if(foot==10){
		for(int i = 2;i<10;i++)
			for(int j =i+1;j<10;j++){
				int a=0,b=0,c=0;
				for(int k=1;k<i;k++) a=a*10+data[k];
				for(int k=i;k<j;k++) b=b*10+data[k];
				for(int k=j;k<10;k++) c=c*10+data[k];
					if(b%c==0)
						if(a+b/c==dst){
							count++;
							//cout<<a<<'+'<<b<<'/'<<c<<endl;
						}
			}
	}
	else
		for(int i = 1;i<10;i++)
			if(book[i]==false){
				book[i]=true;
				data[foot]=i;
				Dfs(foot+1,dst);
				book[i]=false;					
			}
}
int main(){
	int dst;
	cin>>dst;
	Dfs(1,dst);
	cout<<count;
}
