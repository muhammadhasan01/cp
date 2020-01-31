#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
int t[N];
vector<int> g[N];
int sum = 0;
int ans[5], len;

void dfs(int u) {
  for (auto v : g[u]) {
    dfs(v);
    t[u] += t[v];
  }
  if (t[u] == sum) {
    t[u] = 0;
    ans[++len] = u;
    if (len == 3) {
      cout << ans[1] << " " << ans[2] << '\n';
      exit(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int root = -1;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p >> t[i];
    sum += t[i];
    if (p) {
      g[p].push_back(i);
    } else {
      root = i;
    }
  }
  if (sum % 3 != 0) {
    cout << -1 << '\n';
    return 0;
  }
  sum /= 3;
  dfs(root);
  cout << -1 << '\n';

  return 0;
}
