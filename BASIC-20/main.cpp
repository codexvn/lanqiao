#include<iostream>
#include<vector>
using namespace std;
string shu_zi[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" }, \
dan_wei[] = { "","shi","bai","qian" };//"wan","yi"
string get;
vector<string>change;
inline void Function(int end,string yv) {
	static bool zeroed =true;
	bool a=false;
	for (int count = 0; count <= 3 and end >= 0; end--, count++) {
		if (get[end] != '0'){
			zeroed = false;
			if (a == false and yv!="")change.push_back(" "+yv);
				a = true;
		}

		if (zeroed == false)
			if(get[end] == '0')
				change.push_back(" ling");
			else
				if (count > 0)
					change.push_back(" " + shu_zi[get[end] - '0'] + " " + dan_wei[count]);
				else
					change.push_back(" " + shu_zi[get[end] - '0']);

		if (get[end] == '0')
			zeroed = true;
	}  //end:末尾数在get中的下标
	
}
int main() {

	cin >> get;   
	Function(get.length() - 1,"");
	Function(get.length() - 5,"wan");
	Function(get.length() - 9,"yi");

	if (change.front() == " ling")
		change.erase(change.begin());
	if(change.back()==" yi shi")
		change.back()="shi";		
	else	
		change.back().erase(change.back().begin());
	
	if(change.size()==0)
		cout<<endl;
	else 
		for (vector<string>::reverse_iterator i = change.rbegin(); i != change.rend(); i++)
			cout << *i;
}

