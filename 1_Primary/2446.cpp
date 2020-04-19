#include <bits/stdc++.h>

using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int num, j;
  cin >> num;
  for (int i = 0; i < 2 * num - 1; i++) {
    if (i < num) {

      for (j = 0; j < i; j++)
        cout << ' ';
      for (j = 0; j < 2 * num - 2 * i - 1; j++)
        cout << '*';

    } else if (i >= num) {

      for (j = 0; j < num * 2 - i - 2; j++)
        cout << ' ';
      for (j = 0; j < 2 * (i - num + 1) + 1; j++)
        cout << '*';
    }
    cout << '\n';
  }
  return 0;
}