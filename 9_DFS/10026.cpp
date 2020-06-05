#include <bits/stdc++.h>

using namespace std;

string s[100];
int vis[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> s[i];

  // 정상인 기준
  int num = 1;
  stack<pair<int, int>> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 첫 방문시
      if (vis[i][j] == 0) {
        char temp = s[i][j];
        t.push({i, j});
        vis[i][j] = num;

        while (!t.empty()) {
          auto curr = t.top();
          t.pop();

          for (int k = 0; k < 4; k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;

            // 방문한적 없고 첫 글자와 같은 글자라면

            if (vis[nx][ny] == 0 && s[nx][ny] == temp) {
              vis[nx][ny] = num;
              t.push({nx, ny});
            }
          }
        }
        num++;
      }
    }
  }
  // 적록색약
  int num2 = 1;
  stack<pair<int, int>> q;
  // vis 초기화
  for (int i = 0; i < 100; i++) {
    fill(vis[i], vis[i] + 100, 0);
  }
  // R 과 G는 같은 영역이다.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'R' || s[i][j] == 'G')
        s[i][j] = 'R';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 첫 방문시
      if (vis[i][j] == 0) {
        char temp = s[i][j];
        q.push({i, j});
        vis[i][j] = num2;

        while (!q.empty()) {
          auto curr = q.top();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            // 방문한 적 없고 첫 글자와 같은 글자라면
            if (vis[nx][ny] == 0 && s[nx][ny] == temp) {
              vis[nx][ny] = num2;
              q.push({nx, ny});
            }
          }
        }
        num2++;
      }
    }
  }

  cout << num - 1 << ' ' << num2 - 1;
  return 0;
}
