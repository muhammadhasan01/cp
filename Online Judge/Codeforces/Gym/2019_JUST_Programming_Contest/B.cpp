#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n, m, q;
int cnt[N], par[N], sz[N];
bool vis[N];

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

  cin >> tc;
  while (tc--) {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
      cnt[i] = 0;
      vis[i] = 0;
      par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      int l, r;
      cin >> l >> r;
      cnt[l]++;
      cnt[r + 1]--;
    }
    for (int i = 1; i <= m; i++) {
      cnt[i] += cnt[i - 1];
      if (cnt[i] == 0 && cnt[i - 1] == 0) {
        if (i - 1 > 0) merge(i, i - 1);
      }
    }
    vector<pair<int, int>> v;
    for (int i = m; i >= 1; i--) {
      int k = fpar(i);
      if (vis[k]) continue;
      vis[k] = 1;
      if (cnt[i] == 0) {
        v.push_back({sz[k], i});
      }
    }
    sort(v.begin(), v.end());
    int len = v.size();
    vector<int> suf(len + 5);
    for (int i = len - 1; i >= 0; i--) {
      suf[i] = max(suf[i + 1], v[i].second);
    }
    while (q--) {
      int k;
      cin >> k;
      int l = 0, r = len - 1, pos = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid].first >= k) {
          r = mid - 1;
          pos = mid;
        } else {
          l = mid + 1;
        }
      }
      if (pos == -1) {
        cout << -1 << " " << -1 << '\n';
        continue;
      }
      cout << suf[pos] - k + 1 << " " << suf[pos] << '\n';
    }
  }

  return 0;
}
