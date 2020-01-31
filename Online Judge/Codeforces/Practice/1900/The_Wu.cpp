#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int VMAX = (1 << 13);

int n, q, m;
int a[VMAX];
int w[15];
int dp[VMAX][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += (s[i] == '1' ? (1 << i) : 0);
    }
    a[res]++;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      int res = 0;
      for (int k = 0; k < n; k++) {
        bool b1 = i & (1 << k);
        bool b2 = j & (1 << k);
        if ((b1 == 1 && b2 == 1) || (b1 == 0 && b2 == 0)) {
          res += w[k + 1];
        }
        if (res >= N) break;
      }
      if (res >= N) continue;
      dp[i][res] += a[j];
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 1; j < N; j++) {
      dp[i][j] += dp[i][j - 1];
    }
  }
  while (q--) {
    string s;
    int k;
    cin >> s >> k;
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += (s[i] == '1' ? (1 << i) : 0);
    }
    cout << dp[res][k] << '\n';
  }

  return 0;
}
