#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int arrsrc[26], arrcmp[26];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  string src, cmp;
  int result = 1;
  cin >> T;

  while (T--) {
    cin >> src >> cmp;
    for (auto c : src)
      arrsrc[c - 'a']++;

    for (auto c : cmp)
      arrcmp[c - 'a']++;

    for (int i = 0; i < 26; i++) {
      if (arrsrc[i] != arrcmp[i])
        result = 0;
    }
    if (result)
      cout << "Possible" << '\n';
    else
      cout << "Impossible" << '\n';

    fill(arrsrc, arrsrc + 26, 0);
    fill(arrcmp, arrcmp + 26, 0);
    result = 1;
  }
  return 0;
}