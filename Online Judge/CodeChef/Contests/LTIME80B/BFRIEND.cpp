#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int tc;
int n;
long long a, b, c, f;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> a >> b >> c;
    long long ans = INF;
    for (int i = 1; i <= n; i++) {
      cin >> f;
      ans = min(ans, abs(f - b) + abs(f - a) + c);
    }
    cout << ans << '\n';
  }

  return 0;
}
