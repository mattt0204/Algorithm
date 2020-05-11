#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

string board[102];
int dist[102][102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < n; i++)
    fill(dist[i], dist[i] + m, -1);

  queue<pair<int, int>> Q;

  Q.push({0, 0});
  dist[0][0] = 0;
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];
      if (nx < 0 or nx >= n or ny < 0 or ny >= m)
        continue;
      // 방문하지 않았고 1인 경우
      if (dist[nx][ny] == -1 and board[nx][ny] == '1') {
        dist[nx][ny] = dist[curr.first][curr.second] + 1;
        Q.push({nx, ny});
      }
    }
  }
  cout << dist[n - 1][m - 1] + 1;
  return 0;
}
