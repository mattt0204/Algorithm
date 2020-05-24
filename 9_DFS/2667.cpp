#include <bits/stdc++.h>

using namespace std;

string board[25];
int vis[25][25];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[625];

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

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  stack<pair<int, int>> s;
  // 단지 수 , 집의 수
  int sum = 0, area;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 방문한적이 없고 단지라면
      if (vis[i][j] == 0 && board[i][j] == '1') {
        s.push({i, j});
        vis[i][j] = 1;
        area = 1;

        while (!s.empty()) {
          auto curr = s.top();
          s.pop();
          for (int k = 0; k < 4; k++) {
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            // 범위를 벗어나면 지나가기
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            // 방문한 적 없고 단지라면
            if (vis[nx][ny] == 0 && board[nx][ny] == '1') {
              s.push({nx, ny});
              vis[nx][ny] = 1;
              area++;
            }
          }
        }

        arr[sum] = area;
        sum++;
      }
    }
  }
  quickSort(arr, 0, sum - 1);

  cout << sum << '\n';
  for (int i = 0; i < sum; i++) {
    cout << arr[i] << '\n';
  }
  return 0;
}
