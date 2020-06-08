#include <bits/stdc++.h>

using namespace std;

int board[52][52];
int vis[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // m 가로 n은 세로
  int t;
  cin >> t;
  while (t--) {
    int m, n, all;
    cin >> m >> n >> all;
    for (int i = 0; i < 52; i++) {
      fill(board[i], board[i] + 52, 0);
      fill(vis[i], vis[i] + 52, 0);
    }
    while (all--) {
      int x, y;
      cin >> x >> y;
      board[y][x] = 1;
    }
    // 초기화

    queue<pair<int, int>> Q;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 1 and vis[i][j] == 0) {
          Q.push({i, j});
          vis[i][j] = 1;
          sum++;
          while (!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            for (int k = 0; k < 4; k++) {
              int nx = curr.first + dx[k];
              int ny = curr.second + dy[k];
              if (nx < 0 or nx > n - 1 or ny < 0 or ny > m - 1)
                continue;
              if (!vis[nx][ny] and board[nx][ny] == 1) {
                Q.push({nx, ny});
                vis[nx][ny] = 1;
              }
            }
          }
        }
      }
    }
    cout << sum << '\n';
  }

  return 0;
}
