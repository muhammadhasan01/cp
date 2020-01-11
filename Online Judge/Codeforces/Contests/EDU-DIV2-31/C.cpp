#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int p[N];
int par[N], sz[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  if (sz[pu] < sz[pv]) swap(pu, pv);
  sz[pu] += sz[pv];
  par[pv] = pu;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    par[i] = i, sz[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    merge(i, p[i]);
  }
  vector<long long> v;
  for (int i = 1; i <= n; i++) {
    if (i == fpar(i)) {
      v.push_back(sz[i]);
    }
  }
  sort(v.begin(), v.end(), greater<int>());
  long long ans = 0;
  int len = v.size();
  if (len == 1) {
    ans = v[0] * v[0];
  } else {
    v[1] += v[0];
    for (int i = 1; i < len; i++) {
      ans += (v[i] * v[i]);
    }
  }
  cout << ans << '\n';

  return 0;
}
