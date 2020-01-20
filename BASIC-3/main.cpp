#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<char>data(m);
	for (int i=0;i<m;i++)
		data[i]='A'+i;
	for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
				cout<<data[j];
			cout<<endl;
			data.insert(data.begin(),data.front()+1);
			data.pop_back();
		}
}
