#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, n, ans[N];
vector<int> G[N], S[2];
void dfs(int u, int fa, int col) {
  S[col].push_back(u);
  for (int v : G[u]) {
    if (v == fa) continue;
    dfs(v, u, col ^ 1);
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    S[0].clear();
    S[1].clear();
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 20; i >= 0; i--) {
      int lim = min(n, (1 << (i + 1)) - 1);
      int t = (S[0].size() > S[1].size() ? 0 : 1);
      for (int j = (1 << i); j <= lim; j++) {
        ans[S[t].back()] = j;
        S[t].pop_back();
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}