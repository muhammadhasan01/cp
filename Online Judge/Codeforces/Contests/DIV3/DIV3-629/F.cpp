#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 2e5 + 5;

int n;
long long k;
long long a[N];
long long pre[N], suf[N];

long long f(long long x) {
  long long p1 = upper_bound(a + 1, a + 1 + n, x) - a;
  long long p2 = lower_bound(a + 1, a + 1 + n, x) - a;
  if (p1 - p2 >= k) return 0;
  long long dif = k - (p1 - p2);
  long long res = 2e18;
  long long c1 = (x - 1) * (p2 - 1) - pre[p2 - 1];
  long long c2 = suf[p1] - (n - p1 + 1) * (x + 1);
  if (n - p1 + 1 >= dif) {
    res = min(res, c2 + dif);
  }
  if (p2 - 1 >= dif ) {
    res = min(res, c1 + dif);
  }
  res = min(res, c1 + c2 + dif);  
  return res;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  set<long long> st;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    pre[i] = a[i] + pre[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = a[i] + suf[i + 1];
  }
  long long ans = 2e18;
  for (auto e : st) {
    ans = min(ans, f(e));
  }
  cout << ans << '\n';

  return 0;
}