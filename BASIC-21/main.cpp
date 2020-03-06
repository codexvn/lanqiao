#include <iostream>
using namespace std;
inline void An(int n,int flag)
{
	if(n==flag){
		cout<<"sin("<<flag<<')';
		return;
	} 
	else{
		cout<<"sin("<<flag;
		if(flag%2==0)cout<<'+';
			else cout<<'-';
		An(n,flag+1);
		cout<<')';			
	}
}
inline void Sn_s(int n,int flag)
{	
	if(flag==1){
		An(1,1);
		cout<<'+'<<n-flag+1;
		return;
	} 
	else{
		cout<<'(';
		Sn_s(n,flag-1);
		cout<<")";
		An(flag,1);
		cout<<'+'<<n-flag+1;			
	}	
}
int main() {
	int n;
	cin>>n;
	Sn_s(n,n);
	return 0;
}
