#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  // mx의 초기값을 k가 1일때의 최대값으로 기본 설정함
  int mx = *max_element(arr, arr + n);
  // k가 2~n
  for (int k = 2; k <= n; k++) {
    // 연속한 k개의 합을 구하는 알고리즘
    for (int j = 0; j < n - k + 1; j++) {
      int result = 0;
      for (int i = j; i < j + k; i++) {
        result += arr[i];
      }
      if (mx < result) {
        mx = result;
      }
    }
  }
  cout << mx;

  return 0;
}
