#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;

struct st {
  int a, b;
  long long h;
  bool operator<(const st& other) {
    if (b == other.b) return a > other.a;
    return b > other.b;
  }
};

int n;
st p[N];
set<int> st;
map<int, int> mp;
long long t[4 * M];
long long dp[N];
int ord;

void update(int v, int s, int e, int pos, long long val) {
  if (s == e && s == pos) {
    t[v] = max(t[v], val);
    return;
  }
  int mid = (s + e) / 2;
  if (pos <= mid) {
    update(2 * v, s, mid, pos, val);
  } else {
    update(2 * v + 1, mid + 1, e, pos, val);
  }
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

long long get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return 0LL;
  if (l <= s && e <= r) {
    return t[v];
  }
  int mid = (s + e) / 2;
  return max(get(2 * v, s, mid, l, r), get(2 * v + 1, mid + 1, e, l, r));
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].a >> p[i].b >> p[i].h;
    st.insert(p[i].a);
    st.insert(p[i].b);
  }
  for (auto e : st) mp[e] = ++ord;
  for (int i = 1; i <= n; i++) {
    p[i].a = mp[p[i].a];
    p[i].b = mp[p[i].b];
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++) {
    dp[i] = p[i].h + get(1, 0, ord, 0, p[i].b - 1);
    update(1, 0, ord, p[i].a, dp[i]);
  }
  cout << *max_element(dp + 1, dp + 1 + n) << '\n';

  return 0;
}