#include <bits/stdc++.h>

using namespace std;

int n;
map<long long, int> cnt;
long long sum = 0;
int ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  ans = n - 1;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    sum += x;
    ans = min(ans, n - ++cnt[sum]);
  }
  cout << ans << '\n';

  return 0;
}
