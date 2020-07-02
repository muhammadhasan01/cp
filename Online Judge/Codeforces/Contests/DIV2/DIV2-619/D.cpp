#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<pair<int, string>> v;

void solve(int x) {
  if (k <= n) {
    v.push_back({k, "D"});
    return;
  }
  v.push_back({n, "D"});
  k -= n;
  if (x == m) {
    if (k <= n) {
      v.push_back({k, "U"});
      return;
    }
    v.push_back({n, "U"});
    k -= n;
    v.push_back({k, "L"});
    return;
  }
  int l = 0, r = n, best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (3 * mid < k) {
      l = mid + 1;
      best = mid;
    } else {
      r = mid - 1;
    }
  }
  if (k <= 3 * n) {
    if (best > 0) v.push_back({best, "RLU"});
    k -= 3 * best;
    string haha = "RLU";
    v.push_back({1, haha.substr(0, k)});
    return;
  }
  v.push_back({n, "RLU"});
  k -= 3 * n;
  v.push_back({1, "R"});
  if (--k == 0) return;
  solve(x + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  if (2 * (2 * n * m - n - m) < k) {
    cout << "NO" << '\n';
    return 0;
  }
  if (n == 1) {
    cout << "YES" << '\n';
    m--;
    if (k <= m) {
      cout << 1 << '\n';
      cout << k << " " << "R" << '\n';
    } else {
      cout << 2 << '\n';
      cout << m << " " << "R" << '\n';
      cout << k - m << " " << "L" << '\n';
    }
    return 0;
  } else if (m == 1) {
    cout << "YES" << '\n';
    n--;
    if (k <= n) {
      cout << 1 << '\n';
      cout << k << " " << "D" << '\n';
    } else {
      cout << 2 << '\n';
      cout << n << " " << "D" << '\n';
      cout << k - n << " " << "U" << '\n';
    }
    return 0;
  } else {
    n--, m--;
    solve(0);
    cout << "YES" << '\n';
    cout << v.size() << '\n';
    for (auto e : v) {
      cout << e.first << " " << e.second << '\n';
    }
  }

  return 0;
}
