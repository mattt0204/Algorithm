
#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int sub[301][301];
int vis[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int i, j;

  // 입력받기
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int year = 0;
  int kernal;
  bool checkTwo = false;
  while (1) {
    // DFS로 두 덩어리 이상인지 확인하기
    kernal = 0;
    stack<pair<int, int>> s;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {

        if (vis[i][j] == 0 && arr[i][j] > 0) {
          s.push({i, j});
          vis[i][j] = 1;
          while (!s.empty()) {
            auto curr = s.top();
            s.pop();
            for (int k = 0; k < 4; k++) {
              int nx = curr.first + dx[k];
              int ny = curr.second + dy[k];
              if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
              if (vis[nx][ny] == 0 && arr[nx][ny] > 0) {
                s.push({nx, ny});
                vis[nx][ny] = 1;
              }
            }
          }
          kernal++;
        }
      }
    }
    // 초기, iteration 할 때마다 2개 이상인지 체크하고 탈출
    if (kernal >= 2) {
      checkTwo = true;
      break;
    }
    //다 녹았을 때
    else if (kernal == 0) {
      break;
    }
    // 뺄 행렬, 방문 행렬 초기화
    for (i = 0; i < n; i++) {
      fill(sub[i], sub[i] + 300, 0);
      fill(vis[i], vis[i] + 300, 0);
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        // 빙산 발견
        if (arr[i][j] > 0) {
          // i,j 주변의 사방의 바닷 개수 세기.
          for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (arr[nx][ny] == 0)
              sub[i][j]++;
          }
        }
      }
    }
    // 세아려 놓은 것 빼기.
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        // 빙산 줄어든 높이
        arr[i][j] = arr[i][j] - sub[i][j];
        // 음수가 생길경우 0으로 정정
        if (arr[i][j] < 0) {
          arr[i][j] = 0;
        }
      }
    }
    // 확인
    // for (i = 0; i < n; i++) {
    //   for (j = 0; j < m; j++) {
    //     cout << arr[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    year++;
  }

  if (checkTwo)
    cout << year;
  else
    cout << 0;

  return 0;
}
