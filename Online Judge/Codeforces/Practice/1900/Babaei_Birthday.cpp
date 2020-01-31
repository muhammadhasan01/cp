#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long double pi = acos(-1);

int n;
int ord[N];
long long vol[N];
map<long long, int> mp;
set<long long> st;
long long dp[N], pd[N];
long long t[4 * N];

void update(int v, int s, int e, int pos, long long val) {
  if (s == e) {
    t[v] = val;
  } else {
    int mid = (s + e) >> 1;
    if (pos <= mid) {
      update(v << 1, s, mid, pos, val);
    } else {
      update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = max(t[v << 1], t[v << 1 | 1]);
  }
}

long long get(int v, int s, int e, int l, int r) {
  if (s > r || e < l || l > r) return 0LL;
  if (l <= s && e <= r) return t[v];
  int mid = (s + e) >> 1;
  return max(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long r, h;
    cin >> r >> h;
    vol[i] = r * r * h;
    st.insert(vol[i]);
  }
  int cnt = 0;
  for (auto e : st) {
    mp[e] = ++cnt;
  }
  for (int i = 1; i <= n; i++) {
    ord[i] = mp[vol[i]];
  }
  for (int i = 1; i <= n; i++) {
    int pos = ord[i];
    dp[i] = vol[i] + get(1, 1, n, 1, pos - 1);
    if (pd[pos] < dp[i]) {
      pd[pos] = dp[i];
      update(1, 1, n, pos, dp[i]);
    }
  }
  long double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, (long double) dp[i]);
  }
  cout << fixed << setprecision(9) << pi * ans << '\n';

  return 0;
}
