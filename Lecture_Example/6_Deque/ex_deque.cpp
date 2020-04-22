#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) { dat[--head] = x; }
void push_back(int x) { dat[tail++] = x; }
void pop_front() { head++; }
void pop_back() { tail--; }
int front() { return dat[head]; }
int back() { return dat[tail - 1]; }
void test() {
  push_front(-1);
  push_front(-2);
  push_back(1);
  push_back(2);
  cout << front() << '\n';
  cout << back() << '\n';
  pop_back();
  pop_front();
  cout << front() << '\n';
  cout << back() << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  test();

  return 0;
}
