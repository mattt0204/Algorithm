#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int unused = 1;
int pre[MX], dat[MX], nxt[MX];

void traverse() {
  int curr = nxt[0];
  while (curr != -1) {
    cout << dat[curr] << ' ';
    curr = nxt[curr];
  }
  cout << '\n';
}
void insert(int addr, int num) {
  dat[unused] = num;
  nxt[unused] = nxt[addr];
  pre[unused] = addr;
  // 앞에 있던 것에 뒤에 있는 것이 남아 있다면
  if (nxt[addr] != -1) {
    // 뒤에 남은 것의 앞 주소를 현재로 연결해라.
    pre[nxt[addr]] = unused;
  }
  // 앞에 있는 것을 현재로 연결하라.
  nxt[addr] = unused;
  unused++;
}
void insert_test() {
  cout << "Inser_ test\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}
void erase(int addr) {
  // 마지막이라면
  nxt[pre[addr]] = nxt[addr];
  // 마지막이 아니라면
  if (nxt[addr] != -1) {
    pre[nxt[addr]] = pre[addr];
    nxt[addr] = -1;
  }

  pre[addr] = -1;
}

void erase_test() {
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main() {

  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  insert_test();
  erase_test();
  return 0;
}