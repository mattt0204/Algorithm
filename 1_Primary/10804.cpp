#include <bits/stdc++.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int arr[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int nextarr[20];
  int a, b, t;
  for (int m = 0; m < 10; m++) {
    cin >> a >> b;
    for (int i = a - 1; i < a + (b - a) / 2; i++) {
      SWAP(arr[i], arr[a + b - i - 2], t);
    }
  }

  for (int i = 0; i < 20; i++)
    cout << arr[i] << ' ';

  return 0;
}