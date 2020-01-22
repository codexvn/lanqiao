#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	string data1,data2;
	cin>>data1>>data2;
	bool all_same=true;
	if(data1.length()!=data2.length())
		{
			cout<<1;
			return 0;
		}
	else
		{
			int length=data1.length();
			for(int i=0;i<length;i++)
			{
				if(data1[i]!=data2[i])
					if(abs(data1[i]-data2[i])=='a'-'A')
						 all_same=false;
					else
						{
							cout<<4;
							return 0;
						}
			}
		}
		if(all_same)
			cout<<2;
		else 
			cout<<3;
	return 0;
}
