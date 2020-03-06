#include <iostream>
using namespace std;
int main() {
  int k;
  cin >> k;
  int dp_data[21][21] = {0}; //保存dp的数据
  dp_data[2][2] = 2;
  for (int i = 3; i <= k; i++) {
    dp_data[i][i] = 2;
    dp_data[i][2] = i * (i - 1); //至少为2位
  }
  for (int i = 4; i <= k; i++)
    for (int j = 3; j <= k; j++)
      dp_data[i][j] = dp_data[i - 1][j] + dp_data[i - 1][j - 1];

  for (int i = 1; i <= k; i++)
    dp_data[k][0] += dp_data[k][i];
  cout << dp_data[k][0] << endl;
  return 0;
}
