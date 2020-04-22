#include <bits/stdc++.h>

using namespace std;
// BFS 와 Flood Fill 할때 자주 사용

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> Q;
  Q.push(10); // 10
  Q.push(20); // 10 20
  Q.push(30); // 10 20 30

  cout << Q.size() << '\n';
  if (Q.empty())
    cout << "Q is empty \n";
  else
    cout << "Q is not empty \n";

  cout << Q.front() << '\n'; // 10
  cout << Q.back() << '\n';  // 30
  Q.pop();                   // 20 30

  Q.push(40); // 20 30 40

  return 0;
}
