#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
long long ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k >> s;
  n = s.length();
  s = "#" + s + "#";
  deque<long long> pre, suf;
  int c = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      pre.push_back(c);
      c = 1;
      continue;
    }
    c++;
  }
  c = 1;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '1') {
      suf.push_front(c);
      c = 1;
      continue;
    }
    c++;
  }
  int m = pre.size();
  if (k == 0) {
    if (m == 0) {
      long long x = n;
      ans += x * (x + 1) / 2;
    } else {
      ans += (suf[m - 1] * (suf[m - 1] - 1)) / 2;
      for (int i = 0; i < m; i++) {
        ans += (pre[i] * (pre[i] - 1)) / 2;
      }
    }
  } else {
    for (int i = 0; i < m - k + 1; i++) {
      ans += (pre[i] * suf[i + k - 1]);
    }
  }
  cout << ans << '\n';

  return 0;
}
