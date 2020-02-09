#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int bit, length, count = 0; // 10n6只需要用int 
	cin >> bit >> length;
	int** dp_data = new int* [length];
	for (int i = 0; i <= length; i++)
		dp_data[i] = new int[bit + 1];
	if (length == 1)
		cout << bit - 1;
	else {
		for (int i = 0; i < bit; i++)
			dp_data[1][i] = 1; //填充数据
		for (int i = 2; i < length; i++)//i用于表示在倒数第i位 
			for (int j = 0; j <= bit; j++) // j用于从0枚举到bit-1，统计当位数为i+1位时第2位如果为j的话有多少种情况 
				for (int num = 0; num < bit; num++) //k用于 
					if (num != j - 1 and num != j + 1) //寻找第3位可能的数
					{
						dp_data[i][j] += dp_data[i - 1][num];
						dp_data[i][j] %= 1000000007;//防止溢出; 
					}
		//处理第1位数
		for (int i = 1; i < bit; i++) //因为第1位不能为0，所以从1开始
			for (int num = 0; num < bit; num++)
				if (num != i - 1 and num != i + 1) {//寻找第2位可能的数
					count += dp_data[length - 1][num];
					count %= 1000000007;//防止溢出; 
				}
		cout << count;
	}
	return 0;
}
