#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e3 + 5;

int n, m;
int a[N];
int cnt[M];
int dp[M];
int pre[M][M];
long long res = 1;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (m < n) {
    cout << 0 << '\n';
    return 0;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 0; i < m; i++) {
    pre[i][0] = 1;
    for (int j = 1; j <= m; j++) {
      pre[i][j] = (pre[i][j - 1] * i) % m;
    }
  }
  res = (a[2] - a[1]) % m;
  cnt[a[1] % m]++;
  cnt[a[2] % m]++;
  for (int i = 3; i <= n; i++) {
    a[i] %= m;
    for (int j = 0; j < m; j++) {
      int k = ((a[i] - j) % m + m) % m;
      res = (res * pre[k][cnt[j]]) % m;
    }
    cnt[a[i]]++;
  }
  cout << res << '\n';

  return 0;
}