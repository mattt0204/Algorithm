#include <bits/stdc++.h>
#define MAX_SIZE 1000002
using namespace std;
int wanted[MAX_SIZE];
// 방문 체크
int vis[MAX_SIZE];
// 사용했던 노드의 성공,실패
int done[MAX_SIZE];
int cnt;

void DFS(int i) {
  // 방문표시
  vis[i] = 1;
  int next = wanted[i];
  //방문한 적이 없다면
  if (!vis[next])
    DFS(next);
  // 방문했지만 방문이 끝나지 않은 노드라면 사이클
  else if (!done[next]) {

    for (int j = next; j != i; j = wanted[j])
      cnt++;
    // 자기자신
    cnt++;
  }

  done[i] = 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    // 테스트 케이스마다 초기화
    fill(vis, vis + MAX_SIZE, 0);
    fill(done, done + MAX_SIZE, 0);
    cnt = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
      cin >> wanted[i];

    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        DFS(i);
      }
    }

    cout << n - cnt << '\n';
  }

  return 0;
}
