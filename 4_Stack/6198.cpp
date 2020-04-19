#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 * 8;

long long buildings[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> buildings[i];
  }
  stack<int> S;
  long long result = 0;

  for (int i = 0; i < N; i++) {
    // 비어있지 않고 최근의 값이
    while (!S.empty() && S.top() <= buildings[i])
      S.pop();

    S.push(buildings[i]);
    result += S.size() - 1;
  }

  cout << result;

  return 0;
}
