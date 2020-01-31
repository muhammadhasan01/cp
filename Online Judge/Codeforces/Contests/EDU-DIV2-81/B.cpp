#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
long long x;
long long pre[N];
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> x >> s;
    s = "#" + s + "#";
    long long ans = 0;
    if (x == 0) ans++;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + (s[i] == '0' ? 1 : -1);
    }
    bool flag = true;
    long long last = pre[n];
    if (last == 0) {
      for (int i = 1; i <= n; i++) {
        if (pre[i] == x) {
          flag = false;
          break;
        }
      }
    } else {
      for (int i = 1; i <= n; i++) {
        if (abs(x - pre[i]) % abs(last) == 0) {
          long long hm = (x - pre[i]) / last;
          if (hm < 0) continue;
          ans++;
        }
      }
    }
    if (!flag) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }

  return 0;
}
