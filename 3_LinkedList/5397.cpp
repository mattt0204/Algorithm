#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;

    list<char> L;
    // < > -
    list<char>::iterator cursor = L.begin();
    for (auto c : s) {
      if (c == '<' && cursor != L.begin())
        cursor--;
      else if (c == '>' && cursor != L.end())
        cursor++;
      else if (c == '-' && cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      } else if ((c >= 'A' && c <= 'z') || (c >= '0' && c <= '9')) {
        L.insert(cursor, c);
      }
    }
    for (auto c : L)
      cout << c;
    cout << '\n';
  }

  return 0;
}

// <<BP<A>>Cd-
// BAPC
//