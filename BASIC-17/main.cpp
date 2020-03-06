#include <iostream>
using namespace std;
int main() {
  long long N, M, array[30][30] = {0}, resule[2][30][30] = {0}, resule_flag = 1,
                  tmp_flag = 0;
  cin >> N >> M;
  //¶ÁÈ¡Êı¾İ
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> array[i][j];
      resule[resule_flag][i][j] = array[i][j];
    }
  for (int i = 1; i < M; i++) {
    swap(tmp_flag, resule_flag);

    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) {
        int sum = 0;
        for (int m = 0; m < N; m++)
          sum += resule[tmp_flag][j][m] * array[m][k];
        resule[resule_flag][j][k] = sum;
      }
  }
  if (M == 0)
    for (int i = 0; i < N; i++) {
      if (i != 0)
        cout << 0;
      else
        cout << 1;
      for (int j = 1; j < N; j++) {
        cout << ' ';
        if (i != j)
          cout << 0;
        else
          cout << 1;
      }
      cout << endl;
    }
  else if (M == 1)
    for (int i = 0; i < N; i++) {
      cout << array[i][0];
      for (int j = 1; j < N; j++) {
        cout << ' ' << array[i][j];
      }
      cout << endl;
    }
  else
    for (int i = 0; i < N; i++) {
      cout << resule[resule_flag][i][0];
      for (int j = 1; j < N; j++) {
        cout << ' ' << resule[resule_flag][i][j];
      }
      cout << endl;
    }
  return 0;
}
