#include <algorithm>
#include <iostream>
using namespace std;
#define N 1000
int main() {
  int data[N], bigger[N], smaller[N];
  int bigger_length = 0,
      smaller_length = 0; //以bigger[n]结尾的最长递增子序列长度
                          //，以smaller[n]结尾的最长非递增子序列长度
  fill(bigger, bigger + N, 1);
  fill(smaller, smaller + N, 1);
  for (int i = 0; cin >> data[i]; i++) {
    for (int j = 0; j <= i; j++)
      if (data[j] >=
          data[i]) //找到第一个比data[i]大的数，尝试将data[i]追加到data[j]
        smaller[i] = max(smaller[i], smaller[j] + 1);
      else
        bigger[i] = max(bigger[i], bigger[j] + 1);
    bigger_length = max(bigger_length, bigger[i]);
    smaller_length = max(smaller_length, smaller[i]);
  }
  cout << smaller_length << endl << bigger_length;

  return 0;
}
