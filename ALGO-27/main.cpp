#include<iostream>
using namespace std;
struct Node{
	Node *LeftNode=NULL,*RightNode=NULL;
	char value;
};
Node* InitTree(string data){
	Node* tmp=new Node;
	if(data.find('0')!=string::npos)
		if(data.find('1')!=string::npos)
			tmp->value='F';
		else
			tmp->value='B';
	else
		tmp->value='I';
	if(data.size()!=1){
		tmp->LeftNode=	InitTree(string(data.begin(),data.begin()+data.size()/2));
		tmp->RightNode=InitTree(string(data.begin()+data.size()/2,data.end()));
	}
	return tmp;
		
}
void PrintTree(Node* data){
	if(data->LeftNode!= NULL){
		PrintTree(data->LeftNode);
		PrintTree(data->RightNode);
	}
	cout<<data->value;
}
int main(){
	int N;
	string data;
	cin>>N>>data;
	PrintTree(InitTree(data));
}
