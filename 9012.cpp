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
    stack<char> st;
    bool impossible = false;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        st.push('(');
      } else {
        if (st.empty()) {
          impossible = true;
          break;
        }
        st.pop();
      }
    }
    if (impossible || !st.empty())
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }

  return 0;
}
