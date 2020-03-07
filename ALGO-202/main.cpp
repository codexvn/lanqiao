#include <iostream>
#include<bitset>
using namespace std;
int main() {

	int L,R,count=0;
	cin>>L>>R;
	for(int i=L;i<=R;i++){
		bitset<32>bit(i);
		count+=bit.count();
	}
	cout<<count;
	return 0;
}
