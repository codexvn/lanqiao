#include<iostream>
using namespace std;
void PrintTree(string mid, string post){
    int mid_root =mid.find(*post.rbegin());
    if(mid.size()>0){
        cout<<*post.rbegin();
        PrintTree(string(mid.begin(),mid.begin()+mid_root),string(post.begin(),post.begin()+mid_root));
        PrintTree(string(mid.begin()+mid_root+1,mid.end()),string(post.begin()+mid_root,post.end()-1));
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    string pre,mid,post;
    cin>>mid>>post;
    PrintTree(mid,post);
}

