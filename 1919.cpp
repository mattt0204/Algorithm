#include <bits/stdc++.h>

using namespace std;

int arr[26];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2;
  cin >> s1 >> s2;

  for (auto c : s1)
    arr[c - 'a']++;

  for (auto c : s2)
    arr[c - 'a']--;

  int sum = 0;
  for (int i = 0; i < 26; i++) {
    sum = sum + abs(arr[i]);
  }
  cout << sum;
  return 0;
}