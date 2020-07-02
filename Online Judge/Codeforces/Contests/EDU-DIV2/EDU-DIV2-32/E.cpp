#include <bits/stdc++.h>

using namespace std;

const int N = 40;
int n;
long long m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<long long> v1, v2;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    x %= m;
    if (i <= n / 2) v1.push_back(x);
    else v2.push_back(x);
  }
  int l1 = v1.size(), l2 = v2.size();
  set<long long> s1, s2;
  long long ans = 0;
  for (int i = 0; i < (1 << l1); i++) {
    long long sum = 0;
    for (int j = 0; j < l1; j++) {
      int k = (1 << j);
      if (i & k) sum = (sum + v1[j]) % m;
    }
    s1.insert(sum);
  }
  for (int i = 0; i < (1 << l2); i++) {
    long long sum = 0;
    for (int j = 0; j < l2; j++) {
      int k = (1 << j);
      if (i & k) sum = (sum + v2[j]) % m;
    }
    s2.insert(sum);
  }
  for (auto e : s1) {
    long long cur = m - e - 1;
    auto it = s2.upper_bound(cur);
    it--;
    ans = max(ans, e);
    ans = max(ans, (e + *it) % m);
  }
  for (auto e : s2) {
    long long cur = m - e - 1;
    auto it = s1.upper_bound(cur);
    it--;
    ans = max(ans, e);
    ans = max(ans, (e + *it) % m);
  }
  cout << ans << '\n';

  return 0;
}
