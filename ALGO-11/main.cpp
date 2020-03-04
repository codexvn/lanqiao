#include<iostream>
using namespace std;
int main(){
	int N;
	int data[10];
	cin>>N;
	data[0]=1;
	data[1]=2;
	for(int i=2;i<N;i++)
		data[i]=data[i-1]+data[i-2];
	cout<<data[N-1];
}
