#include<iostream>
#include<vector>
using namespace std;
string shu_zi[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" }, \
dan_wei[] = { "","shi","bai","qian" };//"wan","yi"
void change(int end, int yu) {

}
int main() {
	string get;
	cin >> get;
	vector<string>change;
	bool zeroed =true;//判断是否已经处理过0    
	for (int end = get.length() - 1, count = 0; count <= 3 and end >= 0; end--, count++) {
		if (get[end] != '0')
			zeroed = false;
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
	bool wan = false;
	for (int end = get.length() - 5, count = 0; count <= 3 and end >= 0; end--, count++) {

		if (get[end] != '0') {
			zeroed = false;
			if (wan == false)change.push_back(" wan");
			wan = true;
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
	bool yi = false;
	for (int end = get.length() - 9, count = 0; count <= 3 and end >= 0; end--, count++) {

		if (get[end] != '0') {
			zeroed = false;
			if (yi == false)change.push_back(" yi");
			yi = true;
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

