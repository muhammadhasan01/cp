#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int m = 2;
queue<int> q;
int par[N], dp[N];
pair<int, int> ans[N];
int lans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    par[m] = 1;
    dp[m] = dp[par[m]] + 1;
    q.push(m);
    ans[++lans] = {1, m++};
  }
  for (int i = k + 1; i <= n - 1; i++) {
    int p = q.front();
    q.pop();
    par[m] = p;
    dp[m] = dp[par[m]] + 1;
    ans[++lans] = {p, m};
    q.push(m++);
  }
  sort(dp + 1, dp + 1 + n);
  cout << dp[n - 1] + dp[n] << '\n';
  for (int i = 1; i < n; i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }

  return 0;
}
