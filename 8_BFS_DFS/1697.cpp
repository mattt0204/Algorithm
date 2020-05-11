#include <bits/stdc++.h>

using namespace std;

int dist[100002];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(dist, dist + 100002, -1);
  int n, k;

  cin >> n >> k;

  queue<int> Q;

  Q.push(n);

  dist[n] = 0;
  while (!Q.empty()) {

    int curr = Q.front();
    Q.pop();
    // 같다면 거리 출력
    if (curr == k) {
      break;
    }
    // 방문하지 않은 조건 안에 push
    // 계산치가 방문한적이 없고 범위를 벗어나지 않는다면 push and 거리 측정
    int ncurr = curr - 1;
    int pcurr = curr + 1;
    int mcurr = 2 * curr;
    // if and 연산자의 순서는 범위 체크 >> 방문 체크
    if (ncurr > -1 && dist[ncurr] == -1) {
      Q.push(ncurr);
      dist[ncurr] = dist[curr] + 1;
    }
    if (pcurr < 100001 && dist[pcurr] == -1) {
      Q.push(pcurr);
      dist[pcurr] = dist[curr] + 1;
    }

    if (mcurr < 100001 && dist[mcurr] == -1) {
      Q.push(mcurr);
      dist[mcurr] = dist[curr] + 1;
    }
  }
  cout << dist[k];
  return 0;
}
