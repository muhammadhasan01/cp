#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int lef[N], rig[N];
short int c[N][2];
long long dp[N][2];

void dfs(int u, bool dir) {
  c[u][dir] = 1;
  if (dir) {
    if (rig[u] > n) {
      dp[u][dir] = a[u];
    } else if (c[rig[u]][!dir] == 1) {
      dp[u][dir] = -1;
    } else {
      if (c[rig[u]][!dir] == 0) dfs(rig[u], !dir);
      long long gt = dp[rig[u]][!dir];
      dp[u][dir] = (gt == -1 ? gt : a[u] + gt);
    }
  } else {
    if (lef[u] < 1) {
      dp[u][dir] = a[u];
    } else if (c[lef[u]][!dir] == 1) {
      dp[u][dir] = -1;
    } else {
      if (c[lef[u]][!dir] == 0) dfs(lef[u], !dir);
      long long gt = dp[lef[u]][!dir];
      dp[u][dir] = (gt == -1 ? gt : a[u] + gt);
    }
  }
  c[u][dir] = 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    lef[i] = i - a[i];
    rig[i] = i + a[i];
  }
  c[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!c[i][0]) dfs(i, 0);
    if (!c[i][1]) dfs(i, 1);
  }
  for (int i = 1; i < n; i++) {
    cout << (dp[i + 1][0] == -1 ? -1 : i + dp[i + 1][0]) << '\n';
  }

  return 0;
}
