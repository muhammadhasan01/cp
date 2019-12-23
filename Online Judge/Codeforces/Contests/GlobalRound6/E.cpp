#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n, q, s, t, u;
int a[N], c[N];
ll sum;
unordered_map<int, int> mp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += (1LL) * a[i];
  }
  cin >> q;
  while (q--) {
    cin >> s >> t >> u;
    if (mp[s].count(t) == 0) {
      mp[s][t] = u;
      if (++c[u] <= a[u]) sum--;
    } else {
      int cur = mp[s][t];
      if (cur && c[cur]-- <= a[cur]) sum++;
      mp[s][t] = u;
      if (++c[u] <= a[u]) sum--;
    }
    cout << sum << '\n';
  }

  return 0;
}
