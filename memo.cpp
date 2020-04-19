#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int dat[] = {1, 2, 3, 4, 5};
  int pt = dat[0];
  cout << *dat;
  cout << *(dat + 1);
  cout << *(dat + 2);
  cout << *(dat + 3);
  cout << *(dat + 4);

  return 0;
}