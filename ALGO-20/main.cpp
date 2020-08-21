#include<iostream>
using namespace std;
void PrintTree(string mid, string post){
	string::iterator mid_root=mid.find(*post.rend());
	string::iterator post_root_left=post.find(*mid_root-1);
	string::iterator post_root_right=post.find(*mid_root+1);
	PrintTree(string(mid,begin(),mid_root),string(post,begin(), post_root_left));
	PrintTree(string(mid_root+1,mid,end()),string(post_root_right,));
}
int main(){
	std::ios::sync_with_stdio(false);
	string pre,mid,post;
	cin>>mid>>post;
	PrintTree(mid,post);
}
