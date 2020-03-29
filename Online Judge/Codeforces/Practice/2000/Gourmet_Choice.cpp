#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int M = 2 * N;

int n, m;
char a[N][N];
vector<int> g[M];
int par[M], deg[M];
int c[M];
int ans[M];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  par[pv] = pu;
}

void dismiss() {
  cout << "No" << '\n';
  exit(0);
}

bool dfs(int u) {
  c[u] = 1;
  for (auto v : g[u]) {
    if (c[v] == 0) {
      if (dfs(v)) return true;
    } else if (c[v] == 1) {
      return true;
    } 
  }
  c[u] = 2;
  return false;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n + m; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '=') {
        merge(i, j + n);
      }
    }
  }
  for (int i = 1; i <= n + m; i++) fpar(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '=') continue;
      int pi = fpar(i);
      int pj = fpar(j + n);
      if (pi == pj) dismiss();
      if (a[i][j] == '>') swap(pi, pj);
      g[pi].push_back(pj);
      deg[pj]++;
    }
  }
  for (int i = 1; i <= n + m; i++) {
    if (fpar(i) == i && c[i] == 0) {
      if (dfs(i)) dismiss();
    }
  }
  queue<int> q;
  for (int i = 1; i <= n + m; i++) {
    if (fpar(i) == i) {
      if (deg[i] == 0) {
        ans[i] = 1;
        q.push(i);
      }
    }
  }
  int cur = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (--deg[v] == 0) {
        ans[v] = ans[u] + 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n + m; i++) {
    ans[i] = ans[fpar(i)];
    if (ans[i] == 0) dismiss();
  }
  cout << "Yes" << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
  for (int i = n + 1; i <= n + m; i++) {
    cout << ans[i] << (i == n + m ? '\n' : ' ');
  }

  return 0;
}