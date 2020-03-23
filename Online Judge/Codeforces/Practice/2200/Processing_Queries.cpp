#include <bits/stdc++.h>

using namespace std;

int n, b;
long long t, d;
vector<long long> v;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> b;
  v.push_back(0LL);
  for (int i = 1; i <= n; i++) {
    cin >> t >> d;
    int cur = v.end() - upper_bound(v.begin(), v.end(), t);
    if (cur <= b) {
      long long res = max(v.back(), t) + d;
      cout << res << " ";
      v.push_back(res);
    } else {
      cout << -1 << " ";
    }
  }
  cout << '\n';

  return 0;
}