#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 큐의 크기, 뽑아내려고 하는 수의 개수
  int n, m;
  int x, sum = 0;
  cin >> n >> m;
  deque<int> DQ;
  for (int i = 1; i <= n; i++)
    DQ.push_back(i);

  while (m--) {

    cin >> x;
    // 맨 앞이 맞다면
    if (DQ.front() == x) {
      DQ.pop_front();
      continue;
    }

    // 초기화
    int two = 0;

    // x가 앞으로 올때까지
    while (DQ.front() != x) {
      DQ.push_back(DQ.front());
      DQ.pop_front();
      two++;
    }
    // two 보존하기 위해
    int temp = two;
    // 원래대로 돌리기
    while (temp--) {
      DQ.push_front(DQ.back());
      DQ.pop_back();
    }

    int three = 0;
    // x가 앞으로 올때까지
    while (DQ.front() != x) {
      DQ.push_front(DQ.back());
      DQ.pop_back();
      three++;
    }
    // three 보존
    temp = three;
    // 원래대로 되돌리기
    while (temp--) {
      DQ.push_back(DQ.front());
      DQ.pop_front();
    }

    if (two > three) {
      // 3번을 사용
      sum += three;
      while (three--) {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      DQ.pop_front();
    } else {
      // 2번 사용
      sum += two;
      while (two--) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
      }
      DQ.pop_front();
    }
  }
  cout << sum;
  return 0;
}
