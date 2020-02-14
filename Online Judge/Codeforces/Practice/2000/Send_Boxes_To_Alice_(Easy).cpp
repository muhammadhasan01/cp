#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n;
int a[N], len, lenz;
long long pre[N];
long long ans = INF;

void ask(int x) {
  long long res = 0;
  for (int i = x; i <= lenz; i += x) {
    if (x & 1) {
      res += (1LL) * (pre[i] - pre[i - x / 2]);
      res -= (1LL) * (pre[i - x / 2 - 1] - pre[i - x]);
    } else {
      res += (1LL) * (a[i] - a[i - 1]);
    }
  }
  ans = min(ans, res);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    bool b;
    cin >> b;
    if (b) {
      a[++len] = i;
    }
  }
  for (int i = 1; i <= len; i++) {
    pre[i] += (1LL) * a[i] + pre[i - 1];
  }
  lenz = len;
  for (int i = 2; i * i <= len; i++) {
    if (len % i == 0) {
      ask(i);
      while (len % i == 0) len /= i;
    }
  }
  if (len > 1) ask(len);
  if (ans == INF) ans = -1;
  cout << ans << '\n';

  return 0;
}
