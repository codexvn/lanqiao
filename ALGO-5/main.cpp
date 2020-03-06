#include<iostream>

using namespace std;

int main() {
    int MAX = 99999999;
    int dis[20001] = {0}, u[200001] ,v[200001], l[200001];
    fill(dis + 2, dis + 20001, MAX);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>l[i];
    for (int j = 1; j < n; j++) {
        bool all_finished = true;
        for (int i = 1; i <= m; i++) {
            if (dis[v[i]] > dis[u[i]] + l[i]) {
                dis[v[i]] = dis[u[i]] + l[i];
                all_finished = false;
            }
        }

        if (all_finished == true)
            break;
    }
    for (int i = 2; i <= n; i++)
        cout << dis[i]<<endl;
    return 0;
}
