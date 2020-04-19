#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, h;
  // 높이, 인덱스
  stack<pair<int, int>> S;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    // 현재 높이를 입력받음
    cin >> h;
    // 비어있지 않고 이전의 높이가 현재높이보다 작으면 없애라
    while (!S.empty() && S.top().first < h)
      S.pop();
    if (S.empty())
      cout << 0 << ' ';
    else
      cout << S.top().second << ' ';
    S.push(make_pair(h, i));
  }
  return 0;
}
