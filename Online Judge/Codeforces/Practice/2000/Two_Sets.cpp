#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a, b;
int par[N], p[N], vs[N], sta[N];
map<int, int> mp;

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    mp[p[i]] = i;
    par[i] = i;
    sta[i] = 3;
  }
  for (int i = 1; i <= n; i++) {
    if (mp.count(a - p[i])) par[fpar(mp[a - p[i]])] = fpar(i), vs[i] |= 1;
    if (mp.count(b - p[i])) par[fpar(mp[b - p[i]])] = fpar(i), vs[i] |= 2;
  }
  for (int i = 1; i <= n; i++) {
    sta[fpar(i)] &= vs[i];
  }
  for (int i = 1; i <= n; i++) {
    if (sta[i] == 0) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    int st = sta[fpar(i)];
    cout << !(st & 1) << (i == n ? '\n' : ' ');
  }

  return 0;
}
