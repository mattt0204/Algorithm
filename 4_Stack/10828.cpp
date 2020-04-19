#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  stack<int> S;
  while (num--) {
    string op;
    cin >> op;
    if (op == "push") // 무조건 쌍 따옴표 사용
    {
      int x;
      cin >> x;
      S.push(x);
    } else if (op == "top") {
      if (S.empty()) {
        cout << -1 << '\n';
      } else {
        cout << S.top() << '\n';
      }
    } else if (op == "size")
      cout << S.size() << '\n';
    else if (op == "pop") {
      if (S.empty()) {
        cout << -1 << '\n';
      } else {
        cout << S.top() << '\n';
        S.pop();
      }
    }

    else {
      if (S.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
  }

  return 0;
}