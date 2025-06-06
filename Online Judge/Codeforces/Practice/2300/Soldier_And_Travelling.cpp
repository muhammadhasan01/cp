#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int INF = 2e9;

int n, m;
int s, t;
int a[N], b[N];
int res[N][N];
int max_flow, flow;
vector<int> p;

void dismiss() {
  cout << "NO" << '\n';
  exit(0);
}

void augment(int u, int min_edge) {
  if (u == s) {
    flow = min_edge;
    return;
  }
  if (p[u] != -1) {
    augment(p[u], min(min_edge, res[p[u]][u]));
    res[p[u]][u] -= flow;
    res[u][p[u]] += flow;
  }
}

void get_max_flow() {
  max_flow = 0;
  while (1) {
    flow = 0;
    vector<int> dist(N, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    p.assign(N, -1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == t) break;
      for (int v = 0; v < N; v++) {
        if (res[u][v] > 0 && dist[v] == INF) {
          dist[v] = dist[u] + 1;
          q.push(v);
          p[v] = u;
        }
      }
    }
    augment(t, INF);
    if (flow == 0) break;
    max_flow += flow;
  }
} 

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int sum_A = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum_A += a[i];
  }
  int sum_B = 0;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum_B += b[i];
  }
  if (sum_A != sum_B) dismiss();
  s = 0, t = 2 * n + 1;
  for (int i = 1; i <= n; i++) {
    res[s][i] = a[i];
    res[n + i][t] = b[i];
    res[i][n + i] = INF;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    res[u][v + n] = INF;
    res[v][u + n] = INF;
  }
  get_max_flow();
  if (max_flow != sum_A) dismiss();
  cout << "YES" << '\n';  
  for (int i = 1; i <= n; i++) {
    for (int j = n + 1; j <= 2 * n; j++) {
      cout << (res[i][j] == 0 ? 0 : INF - res[i][j]) << (j == 2 * n ? '\n' : ' ');
    }
  }

  return 0;
}