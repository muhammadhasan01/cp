#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int K = 22;
const int M = (1 << K);

int n;
int a[N];
int vis[M], dp[M];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vis[a[i]] = 1;
  }
  for (int i = 0; i < M; i++) {
    if (vis[i]) {
      dp[i] = i;
      continue;
    }
    for (int j = 0; j < K; j++) {
      bool b = i & (1 << j);
      if (b) {
        if (dp[i - (1 << j)]) {
          dp[i] = dp[i - (1 << j)];
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = ((1 << 22) - 1) - a[i];
    if (dp[x] == 0) dp[x] = -1;
    cout << dp[x] << (i == n ? '\n' : ' ');
  }

  return 0;
}