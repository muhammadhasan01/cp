#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int L = ceil(log2(N)) + 5;

struct edge {
  int u, v, w, idx;
  bool operator<(const edge &x) {
    return (w < x.w);
  };
};

int n, m;
int par[N];
int anc[N][L];
int dp[N][L];
int depth[N];
int tin[N], tout[N], tim;
edge edges[N];
vector<pair<int, int>> g[N];
long long mst;
long long ans[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

bool merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return false;
  par[pv] = pu;
  return true;
}

void dfs(int u, int p, int w) {
  depth[u] = 1 + depth[p];
  anc[u][0] = p;
  dp[u][0] = w;
  for (int i = 1; i < L; i++) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    dp[u][i] = max(dp[u][i - 1], dp[anc[u][i - 1]][i - 1]);
  }
  tin[u] = ++tim;
  for (auto e : g[u]) {
    int v = e.first;
    int weight = e.second;
    if (v == p) continue;
    dfs(v, u, weight);
  }
  tout[u] = ++tim;
}

int is_anc(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
  if (is_anc(u, v)) return u;
  if (is_anc(v, u)) return v;
  for (int i = L - 1; i >= 0; i--) {
    if (!is_anc(anc[u][i], v)) {
      u = anc[u][i];
    }
  }
  return anc[u][0];
}

int qr(int u, int v) {
  int ret = 0;
  for (int i = L - 1; i >= 0; i--) {
    if (depth[u] <= depth[anc[v][i]]) {
      ret = max(ret, dp[v][i]);
      v = anc[v][i];
    }
  }
  return ret;
}

int getz(int u, int v) {
  int w = LCA(u, v);
  return max(qr(w, u), qr(w, v));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    edges[i].idx = i;
  }
  sort(edges + 1, edges + 1 + m);
  int cnt_node = 0;
  vector<bool> in_mst(m + 1);
  int root = -1;
  for (int i = 1; i <= m; i++) {
    int node_u = edges[i].u;
    int node_v = edges[i].v;
    int weight = edges[i].w;
    if (merge(node_u, node_v)) {
      if (root == -1) root = node_u;
      g[node_u].push_back({node_v, weight});
      g[node_v].push_back({node_u, weight});
      mst += (1LL) * weight;
      cnt_node++;
      in_mst[edges[i].idx] = 1;
      if (cnt_node == n - 1) break;
    }
  }
  dfs(root, root, 0);
  for (int i = 1; i <= m; i++) {
    int id = edges[i].idx;
    if (in_mst[id]) {
      ans[id] = mst;
    } else {
      ans[id] = mst + (1LL) * (edges[i].w - getz(edges[i].u, edges[i].v));
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
