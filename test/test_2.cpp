#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  int a[m], b[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  // 관계 파악하기
  for (int i = 0; i < m; i++) {
    vector<int> v1;

    v1.push_back(a[i]);
    v1.push_back(b[i]);
  }

  return 0;
}
