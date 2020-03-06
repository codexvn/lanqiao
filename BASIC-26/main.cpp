#include<iostream>
using namespace std;
int main()
{
	string time1[]={"zero","one","two","three", "four", "five","six", "seven", "eight", "nine",  "ten", "eleven", "twelve",  "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen","nineteen","twenty"};
	string time2[]={"","","twenty","thirty","forty","fifty"};
	int h,m;
	cin>>h>>m;
	if(h<=20)
		cout<<time1[h];
	else{
		cout<<time2[h/10];
		cout<<' '<<time1[h%10];
	}
	if(m!=0)
		if(m<=20)
			cout<<' '<<time1[m];
		else{
			cout<<' '<<time2[m/10];
			cout<<' '<<time1[m%10];
		}
	else
		cout<<" o'clock";
}
