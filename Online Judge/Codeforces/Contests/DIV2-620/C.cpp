#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
long long n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    set<int> s;
    map<int, int> left, right;
    for (int i = 1; i <= n; i++) {
      int t, l, r;
      cin >> t >> l >> r;
      if (left.count(t)) {
        left[t] = max(left[t], l);
      } else {
        left[t] = l;
      }
      if (right.count(t)) {
        right[t] = min(right[t], r);
      } else {
        right[t] = r;
      }
      s.insert(t);
    }
    bool flag = true;
    int cur = 0;
    int low = m, high = m;
    for (auto e : s) {
      int dif = e - cur;
      low = max(low - dif, left[e]);
      high = min(high + dif, right[e]);
      cur = e;
      if (low <= high) continue;
      flag = false;
      break;
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
