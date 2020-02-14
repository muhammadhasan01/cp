#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct special {
  int u, v;
  long long w;
  bool operator<(const special& s) {
    return (w < s.w);
  }
};

int n, m;
pair<long long, int> a[N];
long long ans;
special s[N];
int par[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> s[i].u >> s[i].v >> s[i].w;
  }
  sort(a + 1, a + 1 + n);
  sort(s + 1, s + 1 + m);
  int cnt = 0;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (cnt == n - 1) break;
      long long cur = a[i].first + a[j].first;
      while (k <= m && s[k].w < cur) {
        int pu = fpar(s[k].u);
        int pv = fpar(s[k].v);
        if (pu != pv) {
          ans += s[k].w;
          par[pu] = pv;
          cnt++;
        }
        k++;
        if (cnt == n - 1) break;
      }
      int pu = fpar(a[i].second);
      int pv = fpar(a[j].second);
      if (pu != pv) {
        ans += cur;
        par[pu] = pv;
        cnt++;
      }
    }
    if (cnt == n - 1) break;
  }
  cout << ans << '\n';

  return 0;
}
