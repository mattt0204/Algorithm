#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int j = 1;
  while (1) {

    string s;
    int cnt = 0;
    cin >> s;
    stack<char> st;
    if (s[0] == '-')
      break;
    for (unsigned long i = 0; i < s.length(); i++) {
      // 비어 있을때 닫힌 괄호가 나온다면 열린괄호로 바꾼다.
      if (st.empty() && s[i] == '}') {
        cnt++;
        s[i] = '{';
        st.push('{');
      }
      // 비어있지 않은데 닫힌 괄호가 나온다면
      else if (!st.empty() && s[i] == '}') {
        st.pop();
      }
      // 열린괄호는 push.
      else
        st.push('{');
    }
    // 종류가 같은 한 쌍은 반만 고치면 된다.
    cnt = cnt + st.size() / 2;
    cout << j << ". " << cnt << '\n';
    j++;
  }
  return 0;
}
