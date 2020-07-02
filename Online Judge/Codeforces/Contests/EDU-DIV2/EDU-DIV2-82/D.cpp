#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;
int m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    vector<int> cnt(64);
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      sum += (1LL) * x;
      int bit = 0;
      while (x > 1) {
        x /= 2;
        bit++;
      }
      cnt[bit]++;
    }
    if (sum < n) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i <= 60; i++) {
      bool b = (n & (1LL << i));
      if (b) {
        for (int j = 0; j < i; j++) {
          cnt[j + 1] += (cnt[j] / 2);
          cnt[j] %= 2;
        }
        if (cnt[i] > 0) {
          cnt[i]--;
          continue;
        }
        int pos = i;
        for (int j = i + 1; j <= 60; j++) {
          if (cnt[j] > 0) {
            pos = j;
            break;
          }
        }
        ans += (pos - i);
        for (int j = pos; j > i; j--) {
          cnt[j]--;
          cnt[j - 1] += 2;
        }
        cnt[i]--;
      }
    }
    cout << ans << '\n';
  }
  
  return 0;
}
