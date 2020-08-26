#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
inline vector<int> Muitiply(vector<int> data, vector<int> base) {
	vector<int>result(500);
	for (int i = 0; i < 500; ++i) {
		for (int j = 0; j < 500; ++j)
			if (i + j < 500) 
				result[i + j] += data[j] * base[i];
			else
				break;
	}
	int flag = 0;
	for (int j = 0; j <500; ++j) {
		flag += result[j];
		result[j] = flag % 10;
		flag = flag / 10;
	}
	return result;
}
int main() {
	std::ios::sync_with_stdio(false);
	int P;
	cin >> P;
	cout << floor(log10(2) * P) + 1 << endl;
	vector<int>result(500), tmp(500);
	result[0]= 1;
	tmp[0]= 2;
	while (P != 0) {
		if ((P & 1) == 1) 
			result = Muitiply(result, tmp);
		tmp = Muitiply(tmp, tmp);
		P >>= 1;
	}
	(*result.begin())--;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 50; j++)
			cout << result[499-i * 50 -j];
		cout << endl;
	}
	return 0;
}
