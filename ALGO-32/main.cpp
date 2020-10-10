#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int s, t, w;
string data;
bool NextString(char pre_letter = 0, int this_w = 0) {
	static int count = 0;
	if (count == 5) //输出5个之后直接退出 
		exit(0);
	if (this_w + 1 == w) {
		//到达指定宽度 
		if (pre_letter > data[this_w])
			data[this_w] = pre_letter;
		if (data[this_w] + 1 <= t - 1 + 'a') { //如果下一个排序符合要求 
			data[this_w]++;//切换为下一个字母
			cout << data << endl;
			count++;
			return true;
		}
		else {
			data[this_w] = 'a';
			return false;		 //向上一层返回false 
		}
	}
	else {
		if (pre_letter > data[this_w])
			data[this_w] = pre_letter + 1;
		while (data[this_w] + 1 <= t - 1 + 'a') 
		{
			if (NextString(data[this_w], this_w + 1)== false)
			{
				if (data[this_w] + (w-this_w-1) == t - 1 + 'a') 
				{
				//下一层已经无法继续累加
					data[this_w] = 'a';
					return false;
				}else
					data[this_w]++;
			}

		}
	}
}
int main() {
	cin >> s >> t >> w >> data;
	NextString();
}
