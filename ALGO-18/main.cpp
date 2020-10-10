#include <iostream>
#include <vector>
using namespace std;
struct MyStruct {
  string data;
  char times;
};
int n, max_length = 0;
vector<MyStruct> letter_table['z' - 'A'];
void DFS(const string &begin, int this_length) {
  bool finded = false;

  vector<MyStruct>::iterator e = letter_table[begin[0] - 'A'].end();
  for (vector<MyStruct>::iterator i = letter_table[begin[0] - 'A'].begin();
       i != e; i++) {
    if ((*i).times == 2)
      continue;
    if ((*i).data.find(begin) == 0 && (*i).data.size() != begin.size()) {
      finded = true;
      (*i).times++;
      for (int j = begin.size(); j < (*i).data.size(); j++) {
        DFS(string((*i).data.begin() + j, (*i).data.end()),
            this_length + (*i).data.size() - begin.size());
      }
      (*i).times--;
    }
  }
  if (finded == false)
    max_length = max_length < this_length ? this_length : max_length;
}
int main() {
  cin >> n;
  string begin;
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    letter_table[tmp[0] - 'A'].push_back(MyStruct{tmp, 0});
  }
  cin >> begin;
  DFS(begin, begin.size());
  cout << max_length;

  return 0;
}
