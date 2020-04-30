#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502];

int n = 7, m = 10;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int, int>> Q;
  vis[0][0] = 1; // 0,0 방문
  Q.push({0, 0});
  while (!Q.empty()) {
    // 확인하고 꺼내고
    auto curr = Q.front();
    Q.pop();
    // print
    cout << '(' << curr.X << ',' << curr.Y << ')' << "->";
    // 인접칸 확인
    for (int i = 0; i < 4; i++) {
      // 기준점으로부터
      int nx = curr.X + dx[i];
      int ny = curr.Y + dy[i];
      // 범위를 벗어나면
      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      // 파랑색이고 방문안했다면 push, visit 표시
      if (board[nx][ny] == 1 && !vis[nx][ny]) {
        Q.push({nx, ny});
        vis[nx][ny] = 1;
      }
    }
  }
  return 0;
}