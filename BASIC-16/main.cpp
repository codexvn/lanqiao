#include <iostream>
#include <vector>
using namespace std;
int sushu[10000],num=0;
vector<int>unit;
void BreakDown(int now){
	if(now==1) return ;
	for(int i=0;;i++)
	{

		if(now%sushu[i]==0){
			unit.push_back(sushu[i]);
			BreakDown(now/sushu[i]);
			break;
			}
	}
}
int main(int argc, char *argv[]) {
	int i, j;
	for(i=2;i<=10000;i++){
		for(j=2;j<=i/2;j++){
			if(i%j==0)
				break;
		}
		if(j>i/2)
			{
				sushu[num]=i;
				num++;
			}
	}
	int a,b;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		unit.clear();
		BreakDown(i);
		cout<<i<<'='<<unit[0];
		for(vector<int>::iterator k =unit.begin()+1;k!=unit.end();k++)
			cout<<'*'<<*k;
		cout<<endl;
	}
	return 0;	
}
