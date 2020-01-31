#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n;
long long ans;
long long s, v, p;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> s >> v >> p;
      long long cur = p / (s + 1);
      cur = (cur * v);
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }

  return 0;
}
