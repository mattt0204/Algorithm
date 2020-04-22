#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    // 함수 입력
    string op;
    cin >> op;
    // 배열의 수의 개수
    int n;
    cin >> n;
    // 덱 선언
    deque<int> DQ;
    // 배열 입력받기
    string arr;
    cin >> arr;
    // 두자리 수 입력받을 공간
    string temp;

    // 덱에 배열 저장
    for (int i = 0; i < arr.size(); i++) {
      // 시작은 무시
      if (arr[i] == '[')
        continue;
      // 숫자라면
      else if (arr[i] >= '0' && arr[i] <= '9')
        temp += arr[i];
      // 숫자입력이 종료되었다면
      else if (arr[i] == ']' || arr[i] == ',')
        // 숫자입력 받았다면
        if (!temp.empty()) {
          // 정수로 바꿔서 덱에 저장
          DQ.push_back(stoi(temp));
          // 숫자배열 비우기
          temp.clear();
        }
    }

    bool err = false; // error일 경우 true;
    bool left = true; // 뒤집어진다면 false

    // 함수의 개수만금
    for (int i = 0; i < op.size(); i++) { // 뒤집기 표시
      if (op[i] == 'R') {
        left = !left;

      }
      // 앞에꺼 하나 빼기
      else {
        if (DQ.empty()) { // 에러 발생
          err = true;
          cout << "error\n";
          break;
        } else {
          // 왼쪽부터라면
          if (left)
            DQ.pop_front();
          // 뒤집어져 있다면
          else
            DQ.pop_back();
        }
      }
    }

    // 프린트 하기
    // 에러가 아니라면
    if (!err) {

      cout << '[';
      // 앞에서부터 출력이라면
      if (left) {
        while (!DQ.empty()) {
          cout << DQ.front();
          DQ.pop_front();
          if (!DQ.empty())
            cout << ',';
        }
      }
      // 뒤집어서 출력이라면
      else {
        while (!DQ.empty()) {
          cout << DQ.back();
          DQ.pop_back();
          if (!DQ.empty())
            cout << ',';
        }
      }
      cout << "]\n";
    }
  }

  return 0;
}
