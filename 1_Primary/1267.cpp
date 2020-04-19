#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  int arr[n];
  int score[2] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    score[0] += (arr[i] / 30 + 1) * 10;
    score[1] += (arr[i] / 60 + 1) * 15;
  }

  if (score[0] > score[1]) {
    cout << 'M' << ' ' << score[1];
  } else if (score[0] < score[1]) {
    cout << 'Y' << ' ' << score[0];
  } else {
    cout << 'Y' << ' ' << 'M' << ' ' << score[0];
  }
}