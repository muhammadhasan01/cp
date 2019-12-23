#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n, m;
int lmp[N], lpm[N];
map<int, int> mp[N];
map<int, int> pm[N];
int u, v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    mp[b][a]++;
    lmp[b]++;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    pm[y][x]++;
    lpm[y]++;
  }
  for (int i = 1; i <= 1000; i++) {
    u += min(lmp[i], lpm[i]);
    for (auto e : mp[i]) {
      v += min(e.second, pm[i][e.first]);
    }
  }
  cout << u << " " << v << '\n';

  return 0;
}
