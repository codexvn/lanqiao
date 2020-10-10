#include <iostream>
using namespace std;
inline int GCD(int a, int b) {
  if (a < b)
    swap(a, b);
  return b == 0 ? a : GCD(b, a % b);
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int tmp = a * b / GCD(a, b);
  tmp = tmp * c / GCD(tmp, c);
  cout << tmp;
}
