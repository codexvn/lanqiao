#include<iostream>
#include<cstdlib>
using namespace std;
int array[200]={0},N;
int compare(const void* a, const void* b){
	 if(*(int*)a>*(int*)b)return 1;
	 else if(*(int*)a<*(int*)b)return -1;
	 else return 0;
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>array[i];
	qsort(array,N,sizeof(int),compare);
		for(int i=0;i<N;i++)
			{
				cout<<array[i];
					if(i!=N-1)cout<<' ';
			}
}
