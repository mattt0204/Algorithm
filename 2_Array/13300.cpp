#include <bits/stdc++.h>

using namespace std;

int arr[6][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int sex, grade, sum = 0;

  while (n--) {
    cin >> sex >> grade;
    arr[grade - 1][sex]++;
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 2; j++) {
      if (arr[i][j] && arr[i][j] % k != 0)
        sum = sum + arr[i][j] / k + 1;
      else if (arr[i][j] && arr[i][j] % k == 0)
        sum = sum + arr[i][j] / k;
    }
  }
  cout << sum;
  return 0;
}