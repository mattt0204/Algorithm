#include <bits/stdc++.h>

using namespace std;

int height[101][101];
int area[100 + 1];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> height[i][j];
    }
  }

  // 각 침수 레벨
  int limit = 0;
  while (limit != 101) {
    int vis[101][101] = {
        0,
    };
    int num = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // 방문한 적이 없고 limit  높이가 limit보다 크다면 침수당하지 않은
        // 지역을 푸쉬
        if (vis[i][j] == 0 && height[i][j] > limit) {
          q.push({i, j});
          vis[i][j] = 1;
          while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
              int nx = curr.first + dx[k];
              int ny = curr.second + dy[k];
              // 벗어나면 통과
              if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

              if (vis[nx][ny] == 0 && height[nx][ny] > limit) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
              }
            }
          }
          num++;
        }
      }
    }
    area[limit] = num;
    limit++;
  }
  cout << *max_element(area, area + 101);

  return 0;
}
