#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, v;
  cin >> n >> v;
  vector<pair<int, int>> kayak, catamaran;
  for (int i = 1; i <= n; i++) {
    int t, p;
    cin >> t >> p;
    if (t == 1) {
      kayak.push_back({p, i});
    } else {
      catamaran.push_back({p, i});
    }
  }
  sort(kayak.rbegin(), kayak.rend());
  sort(catamaran.rbegin(), catamaran.rend());
  int len_kayak = kayak.size();
  int len_catamaran = catamaran.size();
  vector<long long> dp(len_catamaran + 1);
  for (int i = 1; i <= len_catamaran; i++) {
    dp[i] = dp[i - 1] + (1LL) * catamaran[i - 1].first;
  }
  long long ans = 0;
  long long sum = 0;
  int idx_i = 0, idx_j = 0;
  for (int i = 0, j = 0; i <= min(len_kayak, v); i++) {
    if (i > 0) sum += (1LL) * kayak[i - 1].first;
    j = max(0, min(len_catamaran, (v - i) / 2));
    if (sum + dp[j] > ans) {
      ans = sum + dp[j];
      idx_i = i;
      idx_j = j;
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= idx_i; i++) {
    cout << kayak[i - 1].second << " ";
  }
  for (int i = 1; i <= idx_j; i++) {
    cout << catamaran[i - 1].second << " ";
  }
  cout << '\n';

  return 0;
}
