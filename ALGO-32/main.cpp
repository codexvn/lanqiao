#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int s, t, w;
string data;
bool NextString(char pre_letter = 0, int this_w = 0) {
	static int count = 0;
	if (count == 5) //���5��֮��ֱ���˳� 
		exit(0);
	if (this_w + 1 == w) {
		//����ָ����� 
		if (pre_letter > data[this_w])
			data[this_w] = pre_letter;
		if (data[this_w] + 1 <= t - 1 + 'a') { //�����һ���������Ҫ�� 
			data[this_w]++;//�л�Ϊ��һ����ĸ
			cout << data << endl;
			count++;
			return true;
		}
		else {
			data[this_w] = 'a';
			return false;		 //����һ�㷵��false 
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
				//��һ���Ѿ��޷������ۼ�
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
