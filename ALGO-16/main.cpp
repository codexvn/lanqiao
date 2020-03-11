#include <iostream>
#include<vector>
#include <cstdlib>
#include<cmath>
using namespace std;
int main() {
	int data=30000,base=-2;
	cin>>data>>base;
	int data_bak=data;
	vector<int>bit;
	while(data!=0){
		int inset=data%base;
		if(inset<0){
			inset-=base;
			data+=base;
		}
		bit.push_back(inset);
		data/=base;
	}
	cout<<data_bak<<"=";
	for(int i=bit.size()-1;i>=0;i--)
		if(bit[i]>=10)
			cout<<char(bit[i]+55);
		else
			cout<<bit[i];
	cout<<"(base"<<base<<")";
	return 0;
}
