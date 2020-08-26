#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int N, M, data[10000];
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> data[i];
	for (int i = 0; i < M; ++i)
		next_permutation(data, data + N);
	cout << data[0];
	for (int i = 1; i < N; ++i)
		cout <<" "<< data[i];
	return 0;
}
