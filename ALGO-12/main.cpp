#include <iostream>
#include <vector>
using namespace std;
inline void Print(int n) {
  switch (n) {
  case 0:
    cout << "2(0)";
    break;
  case 1:
    cout << "2";
    break;
  case 2:
    cout << "2(2)";
    break;
  default:
    vector<int> bin_tmp;
    int count = 0; //统计二进制中1的个数
    while (n != 0) {
      int tmp = n % 2;
      if (tmp == 1)
        count++;
      bin_tmp.push_back(tmp); //保存转化成的二进制
      n /= 2;
    }
    for (int i = bin_tmp.size() - 1; i >= 0; i--) {
      if (bin_tmp[i] == 1) {
        if (i > 2) {
          cout << "2(";
          Print(i);
          cout << ")";
        } else
          Print(i);
        if (count > 1)
          cout << '+';
        count--;
      }
    }
  }
}
int main() {
  vector<int> bin;
  int data;
  cin >> data;
  Print(data);
}
