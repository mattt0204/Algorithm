#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;
int dat[MX];
int pt = 0;

void push(int x) { dat[pt++] = x; }
void empty() {
  if (pt == 0)
    cout << 1 << '\n';
  else
    cout << 0 << '\n';
}
void pop() {
  if (pt == 0)
    cout << -1 << '\n';
  else {
    pt--;
    cout << dat[pt] << '\n';
  }
}
void size() { cout << pt << '\n'; }
void top() {
  if (pt == 0)
    cout << -1 << '\n';
  else {
    cout << dat[pt - 1] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, ob;
  string op;
  cin >> n;
  while (n--) {
    cin >> op;
    if (op == "push") {
      cin >> ob;
      push(ob);

    } else if (op == "pop") {
      pop();
    } else if (op == "top") {
      top();
    } else if (op == "empty") {
      empty();
    } else if (op == "size") {
      size();
    }
  }

  return 0;
}