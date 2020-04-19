#include <bits/stdc++.h>

using namespace std;

list<int> josephus(int n, int m);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  // 정답 도출
  list<int> ans = josephus(n, m);
  auto it = ans.begin();
  // 첫번째 원소 출력
  cout << "<" << *it;
  it++;
  // 계속 마지막 원소까지 출력
  for (; it != ans.end(); it++)
    cout << ", " << *it;
  cout << ">"
       << "\n";

  return 0;
}

// 호세퍼스
list<int> josephus(int n, int m) {
  list<int> human;
  list<int> jose;

  // 1 2 3 ... n-1 n 까지 입력
  for (int i = 0; i < n; i++)
    human.push_back(i + 1);

  // 포인터
  auto it = human.begin();

  while (n--) {

    // m-1번 이동
    for (int i = 0; i < m - 1; i++) {
      it++;
      // 끝에 도달하면 맨 처음으로 돌아가라.
      if (it == human.end())
        it = human.begin();
    }
    // 개발
    jose.push_back(*it);
    // it 다음 위치를 반환
    it = human.erase(it);
    // 만약 반환 후의 위치가 마지막 위치라면 처음 위치를 반환
    if (it == human.end())
      it = human.begin();
  }

  return jose;
}