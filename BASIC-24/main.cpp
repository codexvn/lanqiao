#include<iostream>
using namespace std;
int main(){
	int v1,v2,t,s,l,l1=0,l2=0,time,stop_time=0;
	bool rabbit_stop=false;
	
	cin>>v1>>v2>>t>>s>>l;
	for(time=0;l1<l and l2<l;time++){
		if(rabbit_stop==false and stop_time ==0)
			l1+=v1;
		else
			stop_time--;
		l2+=v2; //ÀÛ¼Æ¾àÀë
		if(l1-l2>=t and stop_time==0){
			rabbit_stop=true;
			stop_time=s;
			}
		else 
			rabbit_stop=false; 
	}
	if(l1==l2)
		cout<<'D';
	else if(l1>l2)
		cout<<'R';
	else cout<<'T';
	
	cout<<endl<<time<<endl;
	
	
}
