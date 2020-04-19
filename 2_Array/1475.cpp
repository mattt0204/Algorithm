#include <bits/stdc++.h>

using namespace std;

int freq[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, cnt = 0;
  cin >> n;

  if (n > 0) {
    while (n) {
      freq[n % 10]++;
      n = n / 10;
    }
    if ((freq[6] + freq[9]) % 2 == 0)
      freq[6] = ((freq[6] + freq[9]) / 2);
    else
      freq[6] = (freq[6] + freq[9]) / 2 + 1;

    while (freq[0] || freq[1] || freq[2] || freq[3] || freq[4] || freq[5] ||
           freq[6] || freq[7] || freq[8]) {

      for (int i = 0; i < 9; i++) {
        if (freq[i] > 0)
          freq[i]--;
      }
      cnt++;
    }

    cout << cnt;
  } else
    cout << 1;
  return 0;
}