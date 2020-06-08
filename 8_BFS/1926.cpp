
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

// 방문표시
int arr[502][502];
bool vis[502][502];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, i, j;
  cin >> n >> m;

  int mx = 0, num = 0;
  // 그림 입력
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      cin >> arr[i][j];

  // 각 원소 확인
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      // 만약 원소가 1이고 방문표시가 없다면 방문표시, push (그림의
      // 시작점 발견)
      if (arr[i][j] && !vis[i][j]) {

        // i,j로 BFS  시작할 준비
        queue<pair<int, int>> Q;

        vis[i][j] = 1;
        Q.push({i, j});
        // 그림 개수 증가
        num++;
        int area = 0;
        while (!Q.empty()) {
          auto curr = Q.front();
          Q.pop();
          // 넓이 증가
          area++;
          for (int del = 0; del < 4; del++) {
            int nx = curr.X + dx[del];
            int ny = curr.Y + dy[del];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
              continue;
            if (arr[nx][ny] == 1 && !vis[nx][ny]) {
              Q.push({nx, ny});
              vis[nx][ny] = 1;
            }
          }
        }
        // mx < area 일때 mx에 대입
        mx = max(mx, area);
      }
    }
  }

  cout << num << '\n' << mx;

  return 0;
}
