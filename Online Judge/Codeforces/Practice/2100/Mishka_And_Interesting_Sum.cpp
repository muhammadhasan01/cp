#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m;
int a[N];

struct st {
  int l, r, idx;
  bool operator<(const st& other) {
    if (r == other.r) return l < other.l;
    return r < other.r;
  }
};

st q[N];
set<int> st;
unordered_map<int, int> mp;
int mpz[N];
int pre[N];
int last[N];
int ans[N];
int t[4 * N];

void update(int v, int s, int e, int pos, int val) {
  if (s == e && s == pos) {
    t[v] = val;
  } else {
    int mid = (s + e) >> 1;
    if (pos <= mid) {
      update(v << 1, s, mid, pos, val);
    } else {
      update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = (t[v << 1] ^ t[v << 1 | 1]);
  }
}

int get(int v, int s, int e, int l, int r) {
  if (e < l || s > r || l > r) return 0;
  if (l <= s && e <= r) return t[v];
  int mid = (s + e) >> 1;
  return (get(v << 1, s, mid, l, r) ^ get(v << 1 | 1, mid + 1, e, l, r));
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = (a[i] ^ pre[i - 1]);
    st.insert(a[i]);
  }
  int cnt = 0;
  for (auto e : st) {
    mp[e] = ++cnt;
    mpz[cnt] = e;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].idx = i;
  }
  sort(q + 1, q + 1 + m);
  int curR = 0;
  int i = 1;
  while (i <= m) {
    int l = q[i].l, r = q[i].r;
    while (curR < r) {
      ++curR;
      update(1, 0, n, last[a[curR]], 0);
      update(1, 0, n, curR, mpz[a[curR]]);
      last[a[curR]] = curR;
    }
    ans[q[i].idx] = ((pre[r] ^ pre[l - 1]) ^ get(1, 0, n, l, r));
    i++;
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}