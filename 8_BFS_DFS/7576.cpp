#include <bits/stdc++.h>
#define N 1002
#define M 1002

using namespace std;

int board[1002][1002];
int vis[1002][1002];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  queue<pair<int, int>> Q;

  // 가로 세로
  cin >> m >> n;

  // 방문지 행렬을 -1로 만듬
  for (int i = 0; i < n; i++)
    fill(vis[i], vis[i] + m, -1);

  // 행렬 input
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];

      // 토마토가 있으면 Queue 미리 추가, 방문행렬에 0(시작점)으로 표시
      if (board[i][j] == 1) {
        Q.push({i, j});
        vis[i][j] = 0;
      }
    }
  }
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];
      // 범위가 안벗어나면서 익지 않았는데 방문하지 않은 곳이면
      // 방문확인(날짜),큐추가
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (vis[nx][ny] == -1 && board[nx][ny] == 0) {
          Q.push({nx, ny});
          vis[nx][ny] = vis[curr.first][curr.second] + 1;
        }
      }
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      result = max(result, vis[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 토마토가 없으면서 방문하지 않은 경우가 있다면 -1대입
      if (board[i][j] == 0 && vis[i][j] == -1) {
        result = -1;
      }
    }
  }

  cout << result;

  return 0;
}
