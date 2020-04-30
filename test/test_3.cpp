#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int s[n], e[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> e[i];
  }

  for (int i = 0; i < n; i++) {
    // i가 공격할 수 있는 명수
    int result = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (s[j] < s[i] && s[i] < e[j])
          result++;
      }
    }
    cout << result << '\n';
  }

  return 0;
}
