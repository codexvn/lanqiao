#include <iostream>
#include <vector>
using namespace std;
inline void Sum(vector<int> &data, int N, int count) {
  if (count > 30) {
    cout << "Impossible!";
    return;
  } else {
    vector<int> tmp;
    vector<int>::iterator i = data.begin();
    vector<int>::reverse_iterator j = data.rbegin();
    int flag = 0;
    for (; i != data.end(); i++, j++) {
      //			cout<<*i<<"+"<<*j<<"+"<<flag<<"="<<*i+*j+flag<<" ";
      tmp.insert(tmp.begin(), (*i + *j + flag) % N);
      //			cout<<"insert:"<<(*i+*j+flag)%N<<" ";
      flag = (*i + *j + flag) / N;
      //			cout<<"flag:"<<flag<<endl;
    }
    if (flag != 0)
      tmp.insert(tmp.begin(), flag);
    //		for(int k=0;k<tmp.size();k++)
    //			cout<<tmp[k];
    //		cout<<endl;
    int n = tmp.size() - 1, m = 0;
    for (; n > m; n--, m++)
      if (tmp[n] != tmp[m]) {
        Sum(tmp, N, count + 1);
        return;
      }
    if (n <= m) {
      cout << "STEP=" << count;
      return;
    }
  }
}

int main() {
  int N;
  string a;
  vector<int> M;
  //	cout<<(int)'A'<<" "<<(int)'0'<<endl;
  cin >> N >> a;
  for (int i = 0; i < a.size(); i++)
    if (a[i] >= 'A')
      M.insert(M.begin(), a[i] - '0' - 7);
    else
      M.insert(M.begin(), a[i] - '0');
  Sum(M, N, 1);
}
