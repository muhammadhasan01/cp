#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20);
const int L = 20;
const long long INF = 1e18;

int n;
long long a[N];
long long sp[N][L];
long long up[N];
long long pre[N], suf[N];

long long get(int x, int y) {
  int k = up[y - x + 1];
  return min(sp[x][k], sp[y - (1 << k) + 1][k]);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  up[1] = 0;
  for (int i = 2; i < N; i++) {
    up[i] = up[i >> 1] + 1;
  }
  for (int i = 1; i <= n; i++) {
    sp[i][0] = a[i];
  }
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sp[j][i] = min(sp[j][i - 1], sp[j + (1 << (i - 1))][i - 1]);
    }
  }
  pre[1] = a[1];
  for (int i = 2; i <= n; i++) {
    int l = 0, r = i - 1, best = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(mid, i) < a[i]) {
        best = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    pre[i] = a[i] * (1LL) * (i - best) + pre[best];
  }
  suf[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    int l = i + 1, r = n + 1, best = n + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(i, mid) < a[i]) {
        best = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    suf[i] = a[i] * (1LL) * (best - i) + suf[best];
  }
  long long res = 0;
  int at = 0;
  for (int i = 1; i <= n; i++) {
    long long cur = pre[i] + suf[i] - a[i];
    if (cur > res) {
      res = cur;
      at = i;
    }
  }
  for (int i = at + 1; i <= n; i++) {
    if (a[i] > a[i - 1]) a[i] = a[i - 1];
  }
  for (int i = at - 1; i >= 1; i--) {
    if (a[i] > a[i + 1]) a[i] = a[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}