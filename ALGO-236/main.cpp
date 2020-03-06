#include<iostream>
using namespace std;
int main(){
	string date;
	cin>>date;
	int tmp='a'-'A';
	for(int i=date.length()-1;i>=0;i--){
		if(date[i]>='a' and date[i]<='z')
			date[i]-=tmp;
		else if(date[i]>='A' and date[i]<='Z')
			date[i]+=tmp;
	}
	cout<<date;
}
