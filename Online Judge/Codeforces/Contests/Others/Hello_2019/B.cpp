#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n;
int len[N];
int cnt[M + 5];
int mins[N];
bool ok[N];
long long h;
long long suf[M + 5];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int len;
    cin >> len;
    mins[i] = 2e9;
    int maks = -1;
    vector<int> v(len + 1);
    for (int j = 1; j <= len; j++) {
      int x;
      cin >> x;
      v[j] = x;
      mins[i] = min(mins[i], x);
      maks = max(maks, x);
    }
    bool flag = false;
    for (int j = 1; j < len; j++) {
      if (v[j] < v[j + 1]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cnt[maks]++;
    } else {
      ok[i] = flag;
      h++;
    }
  }
  for (int i = M - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + cnt[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (ok[i]) ans += (1LL) * n;
    else ans += suf[mins[i] + 1] + h;
  }
  cout << ans << '\n';

  return 0;
}
