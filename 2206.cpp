#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string s[1001];
int dist1[1001][1001];
int dist2[1001][10001]; // froom (n-1,m-1)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    fill(dist1[i], dist1[i] + m, -1);
    fill(dist2[i], dist2[i] + m, -1);
  }
  queue<pair<int, int>> Q;
  Q.push({0, 0});
  dist1[0][0] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int x = cur.X + dx[dir];
      int y = cur.Y + dy[dir];
      // 범위를 넘거나 벽이 있거나 방문했을 경우
      if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '1' ||
          dist1[x][y] != -1)
        continue;

      dist1[x][y] = dist1[cur.X][cur.Y] + 1;
      Q.push({x, y});
    }
  }
  // n-1,m-1에서 시작
  Q.push({n - 1, m - 1});
  dist2[n - 1][m - 1] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int x = cur.X + dx[dir];
      int y = cur.Y + dy[dir];
      if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '1' ||
          dist2[x][y] != -1)
        continue;
      dist2[x][y] = dist2[cur.X][cur.Y] + 1;
      Q.push({x, y});
    }
  }
  int min_dist = 0x7fffff;
  if (dist2[0][0] >= 0)     // from (0, 0) to (N-1, M-1)의 경로가 있으면
    min_dist = dist2[0][0]; // 일단 갱신

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 벽이 아니면 관심 없다.
      if (s[i][j] == 0)
        continue;
      // 각 벽들에 대해 사방을 살펴보며 dist1,dist2의 합의 최소를 구함.
      int min_dist1 = 0x7fffff;
      int min_dist2 = 0x7fffff;
      for (int dir = 0; dir < 4; dir++) {
        int x = i + dx[dir];
        int y = j + dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m)
          continue;
        if (dist1[x][y] >= 0)
          min_dist1 = min(min_dist1, dist1[x][y]);
        if (dist2[x][y] >= 0)
          min_dist2 = min(min_dist2, dist2[x][y]);
      }
      min_dist = min(min_dist, min_dist1 + min_dist2 + 1);
    }
  }
  if (min_dist == 0x7fffff)
    cout << -1;
  else
    cout << min_dist;
  return 0;
}
