#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
int n, k;
int d[N], deg[N];
vector<pii> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    if (d[i] > 0) {
      pq.push({d[i], i});
    } else {
      q.push({d[i], i});
    }
  }

  if ((int) q.size() != 1) {
    cout << -1 << '\n';
    return 0;
  }

  while (!q.empty()) {
    int disu = q.top().first;
    int u = q.top().second;
    q.pop();
    while (deg[u] < k && !pq.empty()) {
      int disv = pq.top().first;
      int v = pq.top().second;
      if (disu != disv - 1 || deg[v] == k) {
        break;
      }
      deg[u]++, deg[v]++;
      pq.pop();
      ans.push_back({u, v});
      q.push({disv, v});
    }
  }

  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      cout << -1 << '\n';
      return 0;
    }
  }

  cout << ans.size() << '\n';
  for (auto e : ans) {
    cout << e.first << " " << e.second << '\n';
  }

  return 0;
}
