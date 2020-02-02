#include <iostream>
#include <cstdlib>
using namespace std;
int data[9][9] = {0}, book[9][9] = {0}, flag[2][9], count = 0;
inline void BlackDFS(int step, int n);
inline void DFS(int step, int n);
bool FlagCheck(int n, int flag[9])
{
	for (int i = 1; i <= n - 1; i++)			 //行
		for (int j = i + 1; j <= n; j++)		 //列
			if (flag[i] == flag[j] \		 
			 or j - i == abs(flag[i] - flag[j])) //因为是在每一行取一个位置放棋子因此不需要判断是不是在同一行
				return false;
	return true;
}
inline void DFS(int step, int n)
{
	if (step > n)
	{
		BlackDFS(1, n);
		return;
	}
	else
		for (int j = 1; j <= n; j++)
			if (data[step][j] == 1 and book[step][j] != 1)
			{
				book[step][j] = 1;
				flag[0][step] = j;
				if (FlagCheck(step, flag[0]))
					DFS(step + 1, n);
				book[step][j] = 0;
			}
			else
				continue;
}
inline void BlackDFS(int step, int n)
{
	if (step > n)
	{
		count++;
		return;
	}
	else
		for (int j = 0; j <= n; j++)
		{
			if (data[step][j] == 1 and book[step][j] != 1)
			{
				book[step][j] = 1;
				flag[1][step] = j;
				if (FlagCheck(step, flag[1]))
					BlackDFS(step + 1, n);
				book[step][j] = 0;
			}
			else
				continue;
		}
}
int main()
{

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> data[i][j];
		}
	DFS(1, n);
	cout << count;
}
