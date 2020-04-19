#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;
  vector<char> v;
  int n, i, j = 0;
  cin >> n;
  // 수열 저장
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (i = 1; i <= n; i++) {
    s.push(i);
    v.push_back('+');
    // 비어있지 않으며 입력한 수열과 스택의 마지막 원소가 같다면
    while (!s.empty() && s.top() == arr[j]) {
      s.pop();
      v.push_back('-');
      j++;
    }
  }

  if (!s.empty())
    cout << "NO";
  else
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << '\n';
  return 0;
}
