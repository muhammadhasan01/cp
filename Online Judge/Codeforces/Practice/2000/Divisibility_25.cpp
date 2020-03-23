#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

string s;
int n;
int ans = INF;
int f[15];

// 00
void check00(string s) {
  if (f[0] < 2) return;
  int cnt = 0, res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      res += (n - i - 1);
      cnt++;
      if (cnt == 2) break;
    }
  }
  res--;
  ans = min(ans, res);
}

// 25, 75
void check(int x, string s) {
  if (f[5] == 0 || f[x] == 0) return;
  int pos = 0, res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '5') {
      pos = i;
      break;
    }
  }
  res += (n - pos - 1);
  for (int i = pos; i < n - 1; i++) {
    swap(s[i], s[i + 1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    int alf = (s[i] - '0');
    if (alf == x) {
      pos = i;
      break;
    }
  }
  if (s[0] == '0') {
    bool flag = true;
    for (int i = 1; i < n - 2; i++) {
      if (s[i] != '0') {
        flag = false;
        res += i;
        break;
      }
    }
    if (flag) return;
  }
  res += (n - pos - 2);
  ans = min(ans, res);
}

// 50
void check50(string s) {
  if (f[5] == 0 || f[0] == 0) return;
  int pos = 0, res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      pos = i;
      break;
    }
  }
  res += (n - pos - 1);
  for (int i = pos; i < n - 1; i++) {
    swap(s[i], s[i + 1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '5') {
      pos = i;
      break;
    }
  }
  res += (n - pos - 2);
  ans = min(ans, res);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    f[(int) (s[i] - '0')]++;
  }
  check00(s);
  check50(s);
  check(2, s);
  check(7, s);
  if (ans == INF) ans = -1;
  cout << ans << '\n';

  return 0;
}