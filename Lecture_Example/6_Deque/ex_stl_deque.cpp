#include <bits/stdc++.h>

using namespace std;
// 앞쪽에서 추가와 제거가 필요하면 deque을 사용하는데
// 앞쪽이 필요없다면 vector를 사용해라
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> DQ;
  DQ.push_front(-10); // -10
  DQ.push_back(10);   // -10 10
  DQ.push_front(-20); // -20 -10 10
  DQ.push_back(20);   // -20 -10 10 20

  for (auto x : DQ)
    cout << x << ' '; // -20 -10 10 20
  cout << '\n';
  cout << DQ.size() << '\n'; // 4

  if (DQ.empty())
    cout << "DQ is Empty\n";
  else
    cout << "DQ is not Empty\n";

  DQ.pop_front(); // -10 10 20
  DQ.pop_back();  // -10 10

  cout << DQ.front() << '\n'; // -10
  cout << DQ.back() << '\n';  // 10
  DQ.push_back(19);           // -10 10 19
  DQ[2] = 20; // -10 10 20 .. 3번째에 비어있다면 수정이 불가능. 있는 곳에서만
              // 수정 접근 가능

  DQ.insert(DQ.begin() + 1, 0); // -10 0 10 20
  DQ.insert(DQ.begin(), -20);   // -20 -10 0 10 20
  for (auto x : DQ)
    cout << x << ' '; // -20 -10 0 10 20
  cout << '\n';
  cout << DQ[1]; // - 10
  return 0;
}
