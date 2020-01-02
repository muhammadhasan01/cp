#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m;
int x[N], ans[N];
long long res = 0;
map<int, int> vis;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x + 1, x + 1 + n);
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    vis[x[i]] = 1;
    q.push({x[i], 0});
  }
  int len = 0;
  while (!q.empty()) {
    pair<int, int> temp = q.front();
    int cur = temp.first;
    int dist = temp.second;
    q.pop();
    if (dist > 0) {
      res += (1LL) * dist;
      ans[++len] = cur;
    }
    if (len == m) break;
    for (auto e : {-1, 1}) {
      if (vis[cur + e] == 0) {
        vis[cur + e] = 1;
        q.push({cur + e, dist + 1});
      }
    }
  }
  cout << res << '\n';
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << (i == m ? '\n' : ' ');
  }

  return 0;
}
