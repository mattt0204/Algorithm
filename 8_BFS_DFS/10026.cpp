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
  int num = 1;

  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 방문한적 없다면
      if (vis[i][j] == 0) {
        char temp = s[i][j];

        q.push({i, j});
        vis[i][j] = num;
        while (!q.empty()) {
          auto curr = q.front();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;

            // 방문한적 없고 같다면
            if (vis[nx][ny] = 0 && s[nx][ny] == temp) {
              vis[nx][ny] = num;
              q.push({nx, ny});
            }
          }
        }
        num++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << vis[i][j];
    }
    cout << '\n';
  }
  return 0;
}
