#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int board[301][301];
int vis[301][301];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    int l, x, y, x_target, y_target;
    cin >> l;
    cin >> x >> y;
    cin >> x_target >> y_target;

    if (x == x_target && y == y_target) {
      cout << 0 << '\n';
      continue;
    }

    for (int i = 0; i < l; i++)
      fill(vis[i], vis[i] + 300, -1);

    queue<pair<int, int>> s;
    s.push({x, y});
    vis[x][y] = 0;
    bool answer = false;
    while (!answer) {

      auto curr = s.front();
      s.pop();

      for (int i = 0; i < 8; i++) {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];

        if (nx < 0 || nx >= l || ny < 0 || ny >= l)
          continue;
        // 방문 하지 않았다면
        if (vis[nx][ny] == -1) {
          vis[nx][ny] = vis[curr.first][curr.second] + 1;
          s.push({nx, ny});
          if (nx == x_target && ny == y_target) {
            answer = true;
            break;
          }
        }
      }
    }
    cout << vis[x_target][y_target] << '\n';
  }

  return 0;
}
