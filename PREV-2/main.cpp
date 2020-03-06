#include <iostream>
using namespace std;
char data[1025][1025];
inline void Format(int x_begin, int y_end, int n, int times) {
  if (n + 1 == times) {
    x_begin += 2;
    for (int i = 0; i <= 2; i++) {
      data[x_begin][x_begin + i] = data[x_begin][x_begin - i] = '!';
      data[x_begin + i][x_begin] = data[x_begin - i][x_begin] = '!';
    }

    return;
  }

  for (int i = x_begin + 2, j = y_end - 2; i <= j; i++, j--) {
    data[x_begin][i] = data[x_begin][j] = '$';
    data[x_begin][i] = data[x_begin][j] = '$';
    data[y_end][i] = data[y_end][j] = '$';
    data[y_end][i] = data[y_end][j] = '$';
    data[i][x_begin] = data[j][x_begin] = '$';
    data[i][x_begin] = data[j][x_begin] = '$';
    data[i][y_end] = data[j][y_end] = '$';
    data[i][y_end] = data[j][y_end] = '$';
  }
  data[x_begin + 1][x_begin + 2] = data[x_begin + 2][x_begin + 1] = '$';
  data[x_begin + 1][y_end - 2] = data[x_begin + 2][y_end - 1] = '$';
  data[y_end - 1][y_end - 2] = data[y_end - 2][y_end - 1] = '$';
  data[y_end - 1][x_begin + 2] = data[y_end - 2][x_begin + 1] = '$';
  data[x_begin + 2][x_begin + 2] = data[x_begin + 2][y_end - 2] = '$';
  data[y_end - 2][x_begin + 2] = data[y_end - 2][y_end - 2] = '$';
  Format(x_begin + 2, y_end - 2, n, times + 1);
}
int main() {
  int n, times;
  cin >> n;
  times = 4 * n + 5;
  for (int i = 1; i <= times; i++)
    for (int j = 1; j <= times; j++)
      data[i][j] = '.';
  Format(1, times, n, 1);
  for (int i = 1; i <= times; i++) {
    for (int j = 1; j <= times; j++)
      cout << data[i][j];
    cout << endl;
  }

  return 0;
}
