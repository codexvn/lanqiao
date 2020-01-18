#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int array[200]{0};
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>array[i];
		
	sort(array,array+N);
	cout<<array[0];
	for(int i=1;i<N;i++)
		cout<<' '<<array[i];
	return 0;
}
