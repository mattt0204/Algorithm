#include <bits/stdc++.h>

using namespace std;

const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];

void travel() {
  int curr = nxt[0];
  while (curr != -1) {
    cout << dat[curr];
    curr = nxt[curr];
  }
  cout << '\n';
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);

  string s;
  int n;
  char op, ob;
  cin >> s;
  // 초기 데이터 입력
  for (int i = 0; i < s.length(); i++) {
    dat[i + 1] = s[i];
    pre[i + 1] = i;
    nxt[i] = i + 1;
  }

  int unused = s.length() + 1;
  // 명령문 작성

  int curr = s.length(); // 3
  cin >> n;
  while (n--) {
    // cursor 마지막 자리에 위치

    cin >> op;

    if (op == 'L' && curr != 0) {
      curr = pre[curr];
    }

    else if (op == 'D' && nxt[curr] != -1) {
      curr = nxt[curr];
    } else if (op == 'B' && curr != 0) {
      nxt[pre[curr]] = nxt[curr];
      pre[nxt[curr]] = pre[curr];
      curr = pre[curr];
    } else if (op == 'P') {
      cin >> ob;
      dat[unused] = ob;
      pre[unused] = curr;
      nxt[unused] = nxt[curr];
      // 마지막이 아니라면
      if (nxt[curr] != -1) {
        pre[nxt[curr]] = unused;
      }
      nxt[curr] = unused;
      curr = nxt[curr];
      unused++;
    }
  }

  travel();

  return 0;
}