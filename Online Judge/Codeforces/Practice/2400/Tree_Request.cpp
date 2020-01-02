#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m;
vector<int> g[N];
vector<int> v[N];
vector<vector<int>> pre[N];
int len = 0;
int depth[N];
char a[N];
int tin[N], tout[N], tim = 0;

void dfs(int u, int p, int dist) {
  v[dist].push_back(u);
  tin[u] = ++tim;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, dist + 1);
  }
  tout[u] = ++tim;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
    g[i].push_back(x);
  }
  dfs(1, 1, 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int len = v[i].size();
    if (len == 0) continue;
    pre[i].assign(len + 1, vector<int>(30));
    for (int t = 0; t < 26; t++) {
      for (int j = 0; j < len; j++) {
        if (j > 0) pre[i][j][t] = pre[i][j - 1][t];
        if (a[v[i][j]] - 'a' == t) pre[i][j][t]++;
      }
    }
  }
  while (m--) {
    int vtx, dpth;
    cin >> vtx >> dpth;
    int l1 = 0, r1 = v[dpth].size() - 1, pos1 = -1;
    while (l1 <= r1) {
      int mid = (l1 + r1) >> 1;
      if (tin[v[dpth][mid]] >= tin[vtx]) {
        r1 = mid - 1;
        pos1 = mid;
      } else {
        l1 = mid + 1;
      }
    }
    int l2 = 0, r2 = v[dpth].size() - 1, pos2 = -1;
    while (l2 <= r2) {
      int mid = (l2 + r2) >> 1;
      if (tout[v[dpth][mid]] <= tout[vtx]) {
        l2 = mid + 1;
        pos2 = mid;
      } else {
        r2 = mid - 1;
      }
    }
    if (pos1 == -1 || pos2 == -1) {
      cout << "Yes" << '\n';
      continue;
    }
    int odd = 0;
    for (int t = 0; t < 26; t++) {
      int ri = pre[dpth][pos2][t];
      int le = (pos1 == 0 ? 0 : pre[dpth][pos1 - 1][t]);
      if ((ri - le) & 1) odd++;
      if (odd == 2) break;
    }
    cout << (odd <= 1 ? "Yes" : "No") << '\n';
  }

  return 0;
}
