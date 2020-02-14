#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int block;

struct query {
  int l, r, val, idx;
  bool operator<(const query& q) {
    if (l / block == q.l / block) return r / block < q.r / block;
    return l / block < q.l / block;
  }
};

int n, m;
int c[N];
int tin[N], tout[N], tim;
int cnt[N];
int eul[2 * N], bit[2 * N];
int ans[N];
vector<int> g[N];
int sum[2 * N];
query q[N];

void dfs(int u, int p) {
  tin[u] = ++tim;
  eul[tim] = u;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  tout[u] = ++tim;
  eul[tim] = u;
}

void add(int u) {
  int col = c[eul[u]];
  cnt[col]++;
  if (cnt[col] <= 0) return;
  sum[cnt[col]]++;
}

void del(int u) {
  int col = c[eul[u]];
  cnt[col]--;
  if (cnt[col] < 0) return;
  sum[cnt[col] + 1]--;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  for (int i = 1; i <= m; i++) {
    int v, k;
    cin >> v >> k;
    q[i] = {tin[v], tout[v], k, i};
  }
  n *= 2;
  block = sqrt(1 + n);
  sort(q + 1, q + 1 + m);
  int cur_l = 1, cur_r = 1;
  for (int i = 1; i <= m; i++) {
    int l = q[i].l, r = q[i].r;
    while (cur_l < l) {
      del(cur_l++);
    }
    while (cur_l > l) {
      add(--cur_l);
    }
    while (cur_r <= r) {
      add(cur_r++);
    }
    while (cur_r > r + 1) {
      del(--cur_r);
    }
    ans[q[i].idx] = sum[q[i].val * 2];
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
