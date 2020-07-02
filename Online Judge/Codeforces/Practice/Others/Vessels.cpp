#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, q, t, p, x, k;
int store[N], a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  vector<int> v(n);
  for (int i = 1; i <= n; i++) {
    cin >> store[i];
    v[i - 1] = i;
  }
  cin >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> p >> x;
      auto it = lower_bound(v.begin(), v.end(), p);
      auto start = it;
      do {
        if (it == v.end()) break;
        int idx = *it;
        int canAdd = store[idx] - a[idx];
        int toAdd = (x > canAdd ? canAdd : x);
        a[idx] += toAdd;
        x -= toAdd;
        if (store[idx] == a[idx]) it++;
      } while (x > 0);
      if (start != it) v.erase(start, it);
    } else if (t == 2) {
      cin >> k;
      cout << a[k] << '\n';
    }
  }

  return 0;
}
