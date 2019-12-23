#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct st {
  int x, y;
  long long z;
};

const int N = 1e5 + 5;
int n, m;
ll deg[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    ll d;
    cin >> u >> v >> d;
    deg[u] -= d;
    deg[v] += d;
  }
  int j = 1;
  vector<st> res;
  for (int i = 1; i <= n; i++) {
    while (deg[i] < 0) {
      while (deg[j] <= 0) j++;
      ll d = min(-deg[i], deg[j]);
      deg[i] += d;
      deg[j] -= d;
      res.push_back({i, j, d});
    }
  }
  cout << res.size() << '\n';
  for (auto e : res) {
    cout << e.x << " " << e.y << " " << e.z << '\n';
  }

  return 0;
}
