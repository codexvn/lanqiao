#include<iostream>

using namespace std;

int main() {

    int date[200][200] = {0}, m, n,x=0,y=0;
    int food[4][2] = {{1,  0},
                      {0,  1},
                      {-1, 0},
                      {0,  -1}}, food_num = 0;
    cin >> m >> n;
    int x1 = -1, x2 = m, y1 = 0, y2 = n;//定义边界
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> date[i][j];//获取数据
    for (int count = m * n; count > 1; count--) {
        cout << date[x][y]<<' ';
        switch (food_num) {
            case 0:
                if (x + food[food_num][0] == x2) {
                    x2--;
                    (++food_num) %= 4;
                }
                break;

            case 1:
                if (y + food[food_num][1] == y2) {
                    y2--;
                    (++food_num) %= 4;
                }
                break;
            case 2:
                if (x + food[food_num][0] == x1) {
                    x1++;
                    (++food_num) %= 4;
                }
                break;

            case 3:
                if (y + food[food_num][1] == y1) {
                    y1++;
                    (++food_num) %= 4;
                }
                break;
        }
        x += food[food_num][0];
        y += food[food_num][1];
    }
    cout<<date[x][y];

}
