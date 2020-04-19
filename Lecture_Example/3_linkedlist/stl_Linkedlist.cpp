#include <bits/stdc++.h>

using namespace std;

int main() {
  list<int> L = {1, 2};
  // 주소 iterator 1을 가르키는 중
  list<int>::iterator t = L.begin();

  // 위의 명령을 다음과 같이 사용해도 됨 auto t = L.begin();
  L.push_front(10); // 10 1 2
  L.push_back(5);   // 10 1 2 5
  L.insert(t, 6);   // t(1) 앞에 6 삽입 10 6 1 2 5
  t++;              // t(1) 1칸 전진 => t(2)
  t = L.erase(t); // t가 가르키는 값(2)을 제거 , 그 다음 원소인 5의 위치를 반환.
  cout << *t << '\n'; // 5
  // c++11 이상
  for (int i : L)
    cout << i << ' '; // 10 6 1 5
  cout << '\n';

  //  c++ 11미만
  for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << ' '; /// 10 6 1 5
  cout << '\n';

  return 0;
}