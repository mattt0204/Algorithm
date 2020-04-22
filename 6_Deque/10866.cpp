#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  deque<int> DQ;
  int n;
  cin >> n;
  string op;
  while (n--) {
    cin >> op;
    if (op == "push_front") {
      int x;
      cin >> x;
      DQ.push_front(x);
    } else if (op == "push_back") {
      int y;
      cin >> y;
      DQ.push_back(y);
    } else if (op == "pop_front") {
      if (DQ.empty()) {
        cout << -1 << '\n';
      } else {
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    } else if (op == "pop_back") {
      if (DQ.empty()) {
        cout << -1 << '\n';
      } else {
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }

    } else if (op == "size") {
      cout << DQ.size() << '\n';

    } else if (op == "empty") {
      cout << DQ.empty() << '\n';
    }

    else if (op == "front") {
      if (DQ.empty()) {
        cout << -1 << '\n';
      } else {
        cout << DQ.front() << '\n';
      }
    } else {
      if (DQ.empty()) {
        cout << -1 << '\n';
      } else {
        cout << DQ.back() << '\n';
      }
    }
  }
  return 0;
}
