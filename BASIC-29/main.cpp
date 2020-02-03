#include<iostream>
using namespace std;
int main()
{
	string max,min,result;
	cin>>max>>min;
	if(max.length()<min.length())
		swap(max,min);
	int flag=0;//´æ´¢½øÎ»; 
	string::reverse_iterator max_reverse=max.rbegin(),min_reverse=min.rbegin();	 
	 for(;min_reverse!=min.rend();max_reverse++,min_reverse++){
	 	flag+=((*min_reverse-'0')+(*max_reverse-'0'));
	 	result+=char(flag%10+'0');
	 	flag/=10;
	 }
	 for(;max_reverse!=max.rend();max_reverse++){
	 	flag+=(*max_reverse-'0');
	 	result+=char(flag%10+'0');
	 	flag/=10;
	 }
	 if(flag!=0)
	 	result+=char(flag+'0');
	 for(int i = result.length()-1;i>=0;i--)
		 cout<<result[i];
}
