#include <bits/stdc++.h>

using namespace std;
string s[1001];
int dist[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++)
    fill(dist[i], dist[i] + m, -1);
  // 벽을 하나 깨부수는 것을 어떻게 표현할 것이냐 ?

  queue<pair<int, int>> t;
  // "1" 벽의 위치
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') {
        t.push({i, j});
      }
    }
  }

  // O(n*n*n)
  int total = t.size();
  // 처음 한번은 부수는 것을 허용
  bool first = true;
  int temp = -1;
  // 각각의 벽을 한번씩 지우고 BFS 돌려보고 다시 벽 만들기
  for (int iter = 0; iter < total; iter++) {
    auto c = t.front();
    s[c.first][c.second] = '0';
    t.pop();

    for (int i = 0; i < n; i++)
      fill(dist[i], dist[i] + m, -1);

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    bool mission = false;

    while (!mission) {
      auto curr = q.front();
      q.pop();
      for (int k = 0; k < 4; k++) {
        int nx = curr.first + dx[k];
        int ny = curr.second + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        // 방문하지 않았고 방문 할 수 있다면 PUSH, dist 저장
        if (dist[nx][ny] == -1 && s[nx][ny] == '0') {
          q.push({nx, ny});
          dist[nx][ny] = dist[curr.first][curr.second] + 1;
          // 끝까지 갔다면 성공 표시
          if (nx == n - 1 && ny == m - 1) {
            mission = true;
          }
        }
      }
      // 성공하지 못했지만 q가 비었다면 실패
      if (!mission && q.empty()) {
        break;
      }
    }
    // 성공했을 때만
    if (mission) {
      // 처음에는 저장
      if (first) {
        temp = dist[n - 1][m - 1];
        first = false;

      } // 두번째는 작은 것을 저장
      else if (!first) {
        if (temp > dist[n - 1][m - 1])
          temp = dist[n - 1][m - 1];
      }
    }
    // 다시 벽돌로 바꾸기
    s[c.first][c.second] = '1';
  }
  cout << temp;

  return 0;
}