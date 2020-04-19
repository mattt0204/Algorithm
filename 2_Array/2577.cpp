#include <bits/stdc++.h>

using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int a, b, c;

  unsigned long long number;

  cin >> a >> b >> c;
  number = a * b * c;

  int arr[10] = {
      0,
  };

  while (number) {
    arr[(number % 10)]++;
    number = number / 10;
  }

  for (int i = 0; i < 10; i++)
    cout << arr[i] << '\n';

  return 0;
}