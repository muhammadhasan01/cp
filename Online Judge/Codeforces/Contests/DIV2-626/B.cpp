#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 5;

long long n, m;
long long k;
int a[N], b[N];
long long ans = 0;

void check(long long x, long long y) {
  long long curX = 0, curY = 0;
  for (int i = 1; i <= n - x + 1; i++) {
    if (a[i + x - 1] - a[i - 1] == x) curX++;
  }
  for (int i = 1; i <= m - y + 1; i++) {
    if (b[i + y - 1] - b[i - 1] == y) curY++;
  }
  ans += (curX * curY);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  for (long long i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      check(i, k / i);
      if (i * i != k) check(k / i, i);
    }
  }
  cout << ans << '\n';

  return 0;
}