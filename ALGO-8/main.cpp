#include<iostream>
using namespace std;
int arr[100001];
int tree[262144];
inline void BuildTree(int start,int end,int node_flag){
    if(start==end){
        tree[node_flag]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    int left_node=2*node_flag+1;
    int right_node=2*node_flag+2;
    BuildTree(start,mid,left_node);
    BuildTree(mid+1,end,right_node);
    tree[node_flag]=tree[left_node]+tree[right_node];
}
inline void Update(int start,int end,int node_flag,int arr_flag,int arr_value){
    //cout<<start<<" "<<end<<" "<<node_flag<<" "<<arr_flag<<" "<<arr_value<<endl;
    if(start==end){
        arr[arr_flag]=arr_value;
        tree[node_flag]=arr_value;
        return;
    }
    int mid=(start+end)/2;
    int left_node=2*node_flag+1;
    int right_node=2*node_flag+2;
    if(arr_flag>=start and arr_flag<=mid)
        Update(start,mid,left_node,arr_flag,arr_value);
    else
        Update(mid+1,end,right_node,arr_flag,arr_value);
    tree[node_flag]=tree[left_node]+tree[right_node];
}
inline int QuerySum(int start,int end,int node_flag,int query_start,int query_end){
   //cout<<start<<" "<<end<<" "<<query_start<<" "<<query_end<<endl;
    if(query_start<=start and query_end>=end)
        return tree[node_flag];
    else if(query_end<start or query_start>end)
        return 0;
    else {
        int mid=(start+end)/2;
        int left_node=2*node_flag+1;
        int right_node=2*node_flag+2;
        int sum=0;
        if(mid>=query_start)
            sum+=QuerySum(start,mid,left_node,query_start,query_end);
        if(mid+1<=query_end)
            sum+=QuerySum(mid+1,end,right_node,query_start,query_end);
        return sum;
    }
}
inline void FindMax(int start,int end,int node_flag,int query_start,int query_end,int& max_tmp){
    //cout<<start<<" "<<end<<" "<<query_start<<" "<<query_end<<" "<<max_tmp<<endl;
    if(start==end){
        max_tmp=tree[node_flag]>max_tmp?tree[node_flag]:max_tmp;
        return;
    }
    else if(query_end<start or query_start>end)
        return;
    int mid=(start+end)/2;
    int left_node=2*node_flag+1;
    int right_node=2*node_flag+2;
    FindMax(start,mid,left_node,query_start,query_end, max_tmp);
    FindMax(mid+1,end,right_node,query_start,query_end, max_tmp);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    BuildTree(0,n-1,0);
    int p,x,y; //p:2¨´¡Á¡Â¨¤¨¤D¨ª
    for(int i=0,max_tmp=0;i<m;i++,max_tmp=0){
        cin>>p>>x>>y;
        switch(p){
            case 1 :Update(0,n-1,0,x-1,y);break;
            case 2 :cout<<QuerySum(0,n-1,0,x-1,y-1)<<endl;break;
            case 3:FindMax(0,n-1,0,x-1,y-1,max_tmp);
                cout<<max_tmp<<endl;
                break;
        }
    }

}
