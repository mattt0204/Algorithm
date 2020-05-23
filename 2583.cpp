#include <bits/stdc++.h>

int board[101][101];
int vis[101][101];
int arr[101 * 101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than or
    // equal to pivot
    if (arr[j] <= pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
       at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  // 행과 열, 직사각형 개수
  int m, n, k;
  cin >> m >> n >> k;
  // 직사각형 색칠하기
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 입력은 위아래 거꾸로
    for (int i = y1; i < y2; i++) {
      for (int j = x1; j < x2; j++) {
        board[i][j] = 1;
      }
    }
  }

  stack<pair<int, int>> s;
  int num = 0, area;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // 비어 있고 방문하지 상태면 시작
      if (board[i][j] == 0 && vis[i][j] == 0) {
        area = 1;
        s.push({i, j});
        board[i][j] = 1;
        vis[i][j] = 1;
        while (!s.empty()) {
          auto curr = s.top();
          s.pop();
          for (int k = 0; k < 4; k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            // 범위를 벗어나면 지나가기
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
              continue;
            // 방문하지 않은 상태이고 색칠 되어있지 않다면 방문표시, 넓이 증가,
            if (vis[nx][ny] == 0 && board[nx][ny] != 1) {
              s.push({nx, ny});
              vis[nx][ny] = 1;
              board[nx][ny] = 1;
              area++;
            }
          }
        }
        arr[num] = area;
        num++;
      }
    }
  }
  quickSort(arr, 0, num - 1);

  cout << num << '\n';

  for (int i = 0; i < num; i++)
    cout << arr[i] << ' ';

  return 0;
}
