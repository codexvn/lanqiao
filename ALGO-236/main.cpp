#include<iostream>
using namespace std;
int main(){
	string date;
	cin>>date;
	int tmp='a'-'A';
	for(int i=date.length()-1;i>=0;i--){
		if(date[i]>='a')
			date[i]-=tmp;
		else 
			date[i]+=tmp;
	}
	cout<<date;
}
