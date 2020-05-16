#include <bits/stdc++.h>
using namespace std;

int tomato[101][101][101];
int dist[101][101][101];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 가로 세로 높이
  int n, m, h;
  queue<pair<pair<int, int>, int>> Q;
  cin >> n >> m >> h;

  // dist를 방문하지 않은 상자는 -1로 채우기
  // 세로
  for (int i = 0; i < m; i++) {
    // 가로

    for (int j = 0; j < n; j++) {

      fill(dist[i][j], dist[i][j] + h, -1);
    }
  }

  // 토마토 위치 입력받기
  // 높이
  for (int k = 0; k < h; k++) {
    // 세로
    for (int i = 0; i < m; i++) {
      // 가로
      for (int j = 0; j < n; j++) {
        cin >> tomato[i][j][k];
        // 토마토있고, 익었다면 시작점
        if (tomato[i][j][k] == 1) {
          Q.push({{i, j}, k});
          dist[i][j][k] = 0;
        }
        // 토마토는 있지만 익지 않았다면 할 것은 없다.
        // 토마토가 빈 경우 -1 도 명령할 것 없다.
      }
    }
  }

  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();

    for (int i = 0; i < 6; i++) {
      int nx = curr.first.first + dx[i];
      int ny = curr.first.second + dy[i];
      int nz = curr.second + dz[i];
      // 범위 제외
      if (nx < 0 || ny < 0 || nz < 0 || nx > m || ny > n || nz > h)
        continue;
      // 토마토가 있으면서 방문하지 않은경우에 queue 삽입, 거리 , 토마토 익음
      // 표시
      if (tomato[nx][ny][nz] == 0 && dist[nx][ny][nz] == -1) {
        Q.push({{nx, ny}, nz});
        dist[nx][ny][nz] =
            dist[curr.first.first][curr.first.second][curr.second] + 1;
        tomato[nx][ny][nz] = 1;
      }
    }
  }

  int result = 0;
  bool exitOuterLoop = false;
  // 높이
  for (int k = 0; k < h; k++) {
    // 세로
    for (int i = 0; i < m; i++) {
      // 가로
      for (int j = 0; j < n; j++) {
        // 방문하지도 못했고 아직 익지 않은 토마토가 있다면
        if (tomato[i][j][k] == 0 && dist[i][j][k] == -1) {

          exitOuterLoop = true;
          break;
        }

        result = max(result, dist[i][j][k]);
      }

      if (exitOuterLoop)
        break;
    }

    if (exitOuterLoop)
      break;
  }

  if (exitOuterLoop)
    cout << -1;
  else
    cout << result;

  return 0;
}
