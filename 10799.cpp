#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<char> st;
  int n = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      st.push('(');

    else {
      st.pop();
      // 레이저일때
      if (s[i - 1] == '(') {
        n += st.size();
      }
      // 파이프 끝일때
      else
        n++;
    }
  }
  cout << n;
  return 0;
}
