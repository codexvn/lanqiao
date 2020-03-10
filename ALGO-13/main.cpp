#include <algorithm>
#include <iostream>
using namespace std;
#define N 1000
int main() {
  int data[N], bigger[N], smaller[N];
  int bigger_length = 0,
      smaller_length = 0; //��bigger[n]��β������������г���
                          //����smaller[n]��β����ǵ��������г���
  fill(bigger, bigger + N, 1);
  fill(smaller, smaller + N, 1);
  for (int i = 0; cin >> data[i]; i++) {
    for (int j = 0; j <= i; j++)
      if (data[j] >=
          data[i]) //�ҵ���һ����data[i]����������Խ�data[i]׷�ӵ�data[j]
        smaller[i] = max(smaller[i], smaller[j] + 1);
      else
        bigger[i] = max(bigger[i], bigger[j] + 1);
    bigger_length = max(bigger_length, bigger[i]);
    smaller_length = max(smaller_length, smaller[i]);
  }
  cout << smaller_length << endl << bigger_length;

  return 0;
}
