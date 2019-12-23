#include <bits/stdc++.h>

using namespace std;

struct st {
  int g, mins;
};

const int N = 1e5 + 5;
const int NMAX = (1 << 17);
const int K = 19;
int n;
int s[N], p[N];
int ans[N];
int tc;
pair<int, pair<int, int>> v[2 * N];
int lv;
int bit[N];

unordered_map<int, int> mp;

int pre[NMAX + 1];
st sp[NMAX + 1][K + 1];

st merge(st a, st b) {
  return {__gcd(a.g, b.g), min(a.mins, b.mins)};
}

st query(int l, int r) {
  int k = pre[r - l + 1];
  return merge(sp[l][k], sp[r - (1 << k) + 1][k]);
}

void add(int x) {
  for ( ; x <= N; x += x & -x) bit[x]++;
}

int get(int x) {
  if (x == 0) return 0;
  int ret = 0;
  for ( ; x > 0; x -= x & -x) ret += bit[x];
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    p[i] = s[i];
  }
  sort(p + 1, p + 1 + n);
  int rnk = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] != p[i - 1]) rnk++;
    mp[p[i]] = rnk;
  }
  pre[1] = 0;
  for (int i = 2; i <= NMAX; i++) {
    pre[i] = pre[i >> 1] + 1;
  }
  for (int i = 1; i <= n; i++) {
    sp[i][0] = {s[i], s[i]};
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      sp[i][j] = merge(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    int l, r;
    cin >> l >> r;
    st res = query(l, r);
    if (res.g == res.mins) {
      if (l - 1) v[++lv] = {l - 1, {-mp[res.mins], t}};
      v[++lv] = {r, {mp[res.mins], t}};
    }
    ans[t] = r - l + 1;
  }
  sort(v + 1, v + 1 + lv);
  int i = 1, j = 1;
  while (i <= lv) {
    while (j <= v[i].first) add(mp[s[j++]]);
    if (v[i].second.first < 0) {
      ans[v[i].second.second] += get(-v[i].second.first);
    } else {
      ans[v[i].second.second] -= get(v[i].second.first);
    }
    i++;
  }
  for (int t = 1; t <= tc; t++) {
    cout << ans[t] << '\n';
  }

  return 0;
}
