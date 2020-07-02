#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;
const int N = 2e5 + 5;

int n, k, x;
vector<int> v;
long long ans = 0, res = 1;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x >= n - k + 1) {
      ans += (1LL) * x;
      v.push_back(i);
    }
  }
  int len = v.size();
  for (int i = 0; i < len - 1; i++) {
    res = (res * (v[i + 1] - v[i])) % M;
  }
  cout << ans << " " << res << '\n';
  
  return 0;
}