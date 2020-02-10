#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp_data[1000001][2] = { 0 };
vector<vector<int> >link;
inline void DP(int flag, int pre) {
	if (link[flag].size() == 1) //当到达叶子结点时退出 
		return;
	else {
		for (int i = 0; i < link[flag].size(); i++) {
			if (link[flag][i] != pre) {  //由于领接表中存储的是双向链表，所以存储孩子节点的子节点的数组中会包含父节点，要做一个判断防止死循环
										 //见line: 31-32
				DP(link[flag][i], flag);
				dp_data[flag][false] += max(dp_data[link[flag][i]][true], dp_data[link[flag][i]][false]);//因为有权值，有可能子节点的权值和比父节点权值高 
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
		cin >> dp_data[i][true]; //保存数据	
	link.resize(n + 1);
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);  //创建领接表 
	}
	DP(1, 0);
	cout << max(dp_data[1][true], dp_data[1][false]);
	return 0;
}
