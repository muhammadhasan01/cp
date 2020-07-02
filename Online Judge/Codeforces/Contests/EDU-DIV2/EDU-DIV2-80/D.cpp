#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int INF = 1e9;

int n, m, k;
int a[N][10];
int ansl, ansr;
vector<pair<int, int>> v;

bool can(int x) {
  vector<int> str[k + 5];
  for (int i = 1; i <= n; i++) {
    int mask = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] >= x) mask |= (1 << (j - 1));
    }
    str[mask].push_back(i);
  }
  for (auto e : v) {
    if ((int) str[e.first].size() >= 1 && (int) str[e.second].size() >= 1) {
      ansl = str[e.first][0];
      ansr = str[e.second][0];
      return true;
    }
  }
  if ((int) str[k].size() >= 2) {
    ansl = str[k][0];
    ansr = str[k][1];
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  k = (1 << m) - 1;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k; j++) {
      if ((i | j) == k) v.push_back({i, j});
    }
  }
  int l = 0, r = INF;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ansl << " " << ansr << '\n';

  return 0;
}
