#include <bits/stdc++.h>

using namespace std;

stack<int> S;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;

    if (num == 0)
      S.pop();
    else
      S.push(num);
  }
  int sum = 0;
  int size = S.size();

  while (size--) {
    sum += S.top();
    S.pop();
  }
  cout << sum;
  return 0;
}