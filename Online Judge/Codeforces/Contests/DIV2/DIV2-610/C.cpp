#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
int T, a, b;
pair<int, int> t[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  for (int te = 1; te <= tc; te++) {
    cin >> n >> T >> a >> b;
    int ba = 0, bb = 0;
    for (int i = 1; i <= n; i++) {
      cin >> t[i].second;
      if (t[i].second) bb++;
      else ba++;
    }
    for (int i = 1; i <= n; i++) {
      cin >> t[i].first;
    }
    sort(t + 1, t + 1 + n);
    t[n + 1].first = T + 1;
    t[n + 1].second = 0;
    int ans = 0;
    int ca = 0, cb = 0;
    for (int i = 1; i <= n + 1; i++) {
      long long dif = t[i].first - 1 - ((1LL) * a * ca + (1LL) * b * cb);
      if (dif >= 0) {
        int reqa = min((int) dif / a, ba - ca);
        dif -= (1LL) * reqa * a;
        int reqb = min((int) dif / b, bb - cb);
        ans = max(ans, ca + reqa + cb + reqb);
      }
      if (t[i].second) cb++;
      else ca++;
    }
    cout << ans << '\n';
  }

  return 0;
}
