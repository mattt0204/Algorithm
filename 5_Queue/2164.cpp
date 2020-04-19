#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> Q;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    Q.push(i);

  while (Q.size() != 1) {
    Q.pop();
    int x = Q.front();
    Q.pop();
    Q.push(x);
  }
  cout << Q.front();
  return 0;
}
