#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
bool a[N];
vector<int> c[N];
vector<int> g[2 * N];
int tin[2 * N], link[2 * N], comp[2 * N];
bool on_stack[2 * N];
int tim, cmp;
stack<int> st;

void tarjan(int u) {
  st.push(u);
  on_stack[u] = 1;
  tin[u] = link[u] = ++tim;
  for (auto v : g[u]) {
    if (tin[v] == 0) {
      tarjan(v);
      link[u] = min(link[u], link[v]);
    } else if (on_stack[v]) {
      link[u] = min(link[u], tin[v]);
    }
  }
  if (tin[u] == link[u]) {
    int w = -1;
    ++cmp;
    do {
      w = st.top();
      st.pop();
      comp[w] = cmp;
      on_stack[w] = 0;
    } while (w != u && !st.empty());
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int sz;
    cin >> sz;
    for (int j = 1; j <= sz; j++) {
      int x;
      cin >> x;
      c[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    int u = c[i][0];
    int v = c[i][1];
    if (a[i]) {
      g[2 * u].push_back(2 * v);
      g[2 * v].push_back(2 * u);
      g[2 * u + 1].push_back(2 * v + 1);
      g[2 * v + 1].push_back(2 * u + 1);
    } else {
      g[2 * u].push_back(2 * v + 1);
      g[2 * v + 1].push_back(2 * u);
      g[2 * v].push_back(2 * u + 1);
      g[2 * u + 1].push_back(2 * v);
    }
  }
  for (int i = 0; i < 2 * m; i++) {
    if (!tin[i]) {
      tarjan(i);
    }
  }
  bool flag = true;
  for (int i = 0; i < 2 * m; i += 2) {
    if (comp[i] == comp[i + 1]) {
      flag = false;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << '\n';

  return 0;
}
