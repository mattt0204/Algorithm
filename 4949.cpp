#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    string s;
    getline(cin, s);
    //입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.
    // 온점이 나오면 while문 종료하라
    if (s == ".")
      break;
    // 타당한지
    bool isVailed = true;
    stack<char> S;

    for (auto i : s) {
      if (i == '[' | i == '(') {
        S.push(i);
      } else if (!S.empty() && i == ']') {
        if (S.top() == '[')
          S.pop();
        else {
          isVailed = false;
          break;
        }
      } else if (!S.empty() && i == ')') {
        if (S.top() == '(')
          S.pop();
        else {
          isVailed = false;
          break;
        }
      } else if (S.empty() && (i == ']' || i == ')')) {
        {
          isVailed = false;
          break;
        }
      }
    }

    if (!S.empty())
      isVailed = false;

    if (isVailed)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
