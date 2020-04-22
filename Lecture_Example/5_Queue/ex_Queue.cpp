#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) { dat[tail++] = x; }
void pop() { head++; }
int front() { return dat[head]; }
int back() { return dat[tail - 1]; }
void test() {
  push(10);
  push(20);
  push(30);
  cout << front() << '\n'; // 10
  cout << back() << '\n';  // 30
  pop();
  push(40);
  cout << front() << '\n'; // 20
  cout << back() << '\n';  // 40
}
int main() {
  test();
  return 0;
}
