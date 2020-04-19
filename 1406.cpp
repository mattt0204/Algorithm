#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int n;
  char op, ob;
  cin >> s;
  cin >> n;
  list<char> L;
  for (auto c : s)
    L.push_back(c);
  auto curr = L.end();
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == 'L') {
      if (curr != L.begin())
        curr--;
    } else if (op == 'D') {
      if (curr != L.end())
        curr++;
    } else if (op == 'B') {
      if (curr != L.begin()) {
        curr--;
        curr = L.erase(curr);
      }
    } else {
      cin >> ob;
      L.insert(curr, ob);
    }
  }
  for (auto c : L)
    cout << c;

  return 0;
}