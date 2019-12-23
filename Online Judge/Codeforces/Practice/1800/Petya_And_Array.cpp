#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n;
long long t;
long long a[N];
vector<long long> bit[N];
long long ans;

void add(int x, long long val) {
  for ( ; x <= n; x += x & -x) bit[x].push_back(val);
}

int query(int x, long long val) {
  int ret = 0;
  for ( ; x > 0; x -= x & -x) {
    int cur = (int) bit[x].size() - (upper_bound(bit[x].begin(), bit[x].end(), val) - bit[x].begin());
    ret += cur;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    add(i, a[i]);
  }
  for (int i = 1; i <= n; i++) sort(bit[i].begin(), bit[i].end());
  for (int i = 1; i <= n; i++) {
    long long cur = (1LL) * query(i - 1, a[i] - t) + (a[i] < t ? 1LL : 0LL);
    ans += cur;
  }
  cout << ans << '\n';

  return 0;
}
