#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp_data[1000001][2] = { 0 };
vector<vector<int> >link;
inline void DP(int flag, int pre) {
	if (link[flag].size() == 1) //������Ҷ�ӽ��ʱ�˳� 
		return;
	else {
		for (int i = 0; i < link[flag].size(); i++) {
			if (link[flag][i] != pre) {  //������ӱ��д洢����˫���������Դ洢���ӽڵ���ӽڵ�������л�������ڵ㣬Ҫ��һ���жϷ�ֹ��ѭ��
										 //��line: 31-32
				DP(link[flag][i], flag);
				dp_data[flag][false] += max(dp_data[link[flag][i]][true], dp_data[link[flag][i]][false]);//��Ϊ��Ȩֵ���п����ӽڵ��Ȩֵ�ͱȸ��ڵ�Ȩֵ�� 
				dp_data[flag][true] += dp_data[link[flag][i]][false];
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dp_data[i][true]; //��������	
	link.resize(n + 1);
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);  //������ӱ� 
	}
	DP(1, 0);
	cout << max(dp_data[1][true], dp_data[1][false]);
	return 0;
}
