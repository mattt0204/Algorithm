#include <bits/stdc++.h>

using namespace std;

int main() {
  stack<int> S;
  S.push(10);
  cout << S.top() << '\n'; // 10
  S.push(20);
  cout << S.top() << '\n'; // 20
  S.push(30);
  cout << S.top() << '\n';  // 30
  cout << S.size() << '\n'; // 3
  if (S.empty())
    cout << "S is empty\n";
  else
    cout << "S is not empty\n";

  cout << S.top() << '\n'; // 30
  S.pop();
  cout << S.top() << '\n'; // 20

  S.pop();
  cout << S.top() << '\n'; // 10
  S.pop();
  cout << S.top() << '\n'; // waste 값
  if (S.empty())
    cout << "S is empty\n";
  else
    cout << "S is not empty\n";

  return 0;
}