#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> PAIR;
typedef pair<PAIR, bool> PAIR_kind; // true : sangeun move, false : fire move

int depth[1002][1002];
int fire_depth[1002][1002];
string s[1000];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isInBounds(int a, int b, int h, int w) {
  if (a < 0 && a >= h)
    return false;
  if (b < 0 && b >= w)
    return false;
  return true;
};
bool isEscaped(int a, int b, int h, int w) {
  if (a == 0 || a == h - 1 || b == 0 || b == w - 1)
    return true;
  else
    return false;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, h, n;
  int i, j;
  // 케이스 개수
  cin >> n;
  while (n--) {
    // 1 case 입력받기
    cin >> w >> h;

    for (i = 0; i < h; i++) {
      cin >> s[i];
    }
    queue<PAIR_kind> Q;
    int S_i, S_j;
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        if (s[i][j] == '#') {
          depth[i][j] = -2; // impossible
          fire_depth[i][j] = -2;
        } else if (s[i][j] == '*') {
          fire_depth[i][j] = 0;
          depth[i][j] = -1;
          Q.push({{i, j}, false}); // fire
        } else if (s[i][j] == '@') {
          depth[i][j] = 0;
          fire_depth[i][j] = -1;
          S_i = i;
          S_j = j; // sangeun
        } else {
          depth[i][j] = -1;
          fire_depth[i][j] = -1;
        }
      }
    }
    Q.push({{S_i, S_j}, true});
    bool escaped = false;
    while (!Q.empty()) {
      PAIR_kind curr = Q.front();
      int x = curr.X.X;
      int y = curr.X.Y;
      bool isSangeun = curr.Y;

      if (isSangeun && isEscaped(x, y, h, w)) {
        cout << 1 << '\n';
        escaped = true;
        break;
      }
      Q.pop();

      for (int dir = 0; dir < 4; dir++) {
        int test_x = x + dx[dir];
        int test_y = y + dy[dir];
        if (!isInBounds(test_x, test_y, h, w))
          continue;
        // 상근이가
        if (isSangeun) {
          // 종착점이 아니면서 갈 수 있다면
          if (!isEscaped(test_x, test_y, h, w) && depth[test_x][test_y] == -1) {
            Q.push({{test_x, test_y}, isSangeun});
            depth[test_x][test_y] = depth[x][y] + 1;
          }
          // 상근이가 탈출이 가능한 지점에 도착햇을 때
          // 벽이 아니고, 불이 아직 안 왔을 때만
          else if (isEscaped(test_x, test_y, h, w) &&
                   depth[test_x][test_y] != -2 &&
                   fire_depth[test_x][test_y] == -1) {
            escaped = true;
            cout << depth[x][y] + 2 << '\n';
            break;
          }
        } // 불이
        else {
          if (fire_depth[test_x][test_y] == -1) {
            Q.push({{test_x, test_y}, isSangeun});
            fire_depth[test_x][test_y] = fire_depth[x][y] + 1;
          }
        }
      }
      if (escaped)
        break;
    }
    // 검사
    // cout << "sangeun" << '\n';
    // for (i = 0; i < h; i++) {
    //   for (j = 0; j < w; j++) {
    //     if (depth[i][j] >= 0)
    //       cout << ' ';
    //     cout << depth[i][j];
    //   }
    //   cout << '\n';
    // }
    // cout << "fire" << '\n';
    // for (i = 0; i < h; i++) {
    //   for (j = 0; j < w; j++) {
    //     if (fire_depth[i][j] >= 0)
    //       cout << ' ';
    //     cout << fire_depth[i][j];
    //   }
    //   cout << '\n';
    // }

    if (!escaped)
      cout << "IMPOSSIBLE" << '\n';
  }

  return 0;
}
