#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;
int dat[MX];
int pos = 0;

void push(int x) { dat[pos++] = x; }
void pop() { pos--; }

int top() { return dat[pos - 1]; }

void test() {
  push(1);
  cout << top();
  push(2);

  cout << top();
  push(3);

  cout << top();

  cout << '\n';

  cout << top();
  pop();

  cout << top();
  pop();
  cout << top();
  pop();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  test();
  cout << '\n';

  return 0;
}