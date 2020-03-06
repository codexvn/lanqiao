#include <iostream>
#include <set>
using namespace std;
int main() {
  int A_num, B_num, tmp;
  set<int> a, b, c, A_data, B_data;
  cin >> A_num;
  for (int i = 1; i <= A_num; i++) {
    cin >> tmp;
    b.insert(tmp);
    A_data.insert(tmp);
  }
  cin >> B_num;
  for (int i = 1; i <= B_num; i++) {
    cin >> tmp;
    b.insert(tmp);
    B_data.insert(tmp);
  }

  for (set<int>::iterator i = b.begin(); i != b.end(); i++) {
    if (A_data.find(*i) != A_data.end()) {
      if (B_data.find(*i) != B_data.end()) //½»¼¯
        a.insert(*i);
      else
        c.insert(*i); //²¹¼¯
    }
  }
  if (a.empty() != true) {
    set<int>::iterator end = a.end();
    end--;
    for (set<int>::iterator i = a.begin(); i != end; i++)
      cout << *i << " ";
    cout << *end << endl;
  }

  if (b.empty() != true) {
    set<int>::iterator end = b.end();
    end--;
    for (set<int>::iterator i = b.begin(); i != end; i++)
      cout << *i << " ";
    cout << *end << endl;
  }
  if (c.empty() != true) {
    set<int>::iterator end = c.end();
    end--;
    for (set<int>::iterator i = c.begin(); i != end; i++)
      cout << *i << " ";
    cout << *end << endl;
  }
}
