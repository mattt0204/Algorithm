#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  stack<char> st;
  int temp = 1;
  long long result = 0;
  bool impossible = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      st.push('(');
      temp *= 2;
    } else if (s[i] == '[') {
      st.push('[');
      temp *= 3;
    }

    else if (s[i] == ')') {
      if (s[i - 1] == '(')
        result += temp;
      else if (st.empty() || st.top() != '(') {
        impossible = true;
        break;
      }
      temp /= 2;
      st.pop();
    }

    else if (s[i] == ']') {
      if (s[i - 1] == '[')
        result += temp;
      else if (st.empty() || st.top() != '[') {
        impossible = true;
        break;
      }
      st.pop();
      temp /= 3;
    }
  }
  if (!st.empty() || impossible)
    cout << 0;
  else
    cout << result;
  return 0;
}
