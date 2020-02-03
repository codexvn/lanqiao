#include<iostream>
using namespace std;
inline string& Sub(string &data,int n){
	if(n==1){
		data+=n+'0';
		return data;
	}
	int flag=0;//±£´æ½øÎ» 
	for(string::reverse_iterator i = data.rbegin(); i !=data.rend();i++ ){
		flag+=((*i-'0')*n);
		*i=flag%10+'0';
		flag/=10;
	}
	while(flag!=0){
		data.insert(data.begin(),(flag%10)+'0');
		flag/=10;
	}
		
	return data;
}
int main()
{
        int n;
        cin>>n;
        string result;
        for(int i=1;i<=n;i++){
        	result=Sub(result,i);
        }
        cout<<result;
}

