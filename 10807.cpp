#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, target, cnt = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cin >> target;

  for (int i = 0; i < n; i++)
    if (arr[i] == target)
      cnt++;

  cout << cnt;
  return 0;
}