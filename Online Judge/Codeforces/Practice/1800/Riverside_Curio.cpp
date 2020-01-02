#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int m[N];
int low[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
  }
  low[1] = 1;
  for (int i = 2; i <= n; i++) {
    low[i] = low[i - 1];
    if (m[i] > low[i - 1]) low[i]++;
    low[i] = max(low[i], m[i] + 1);
  }
  for (int i = n - 1; i >= 1; i--) {
    low[i] = max(low[i + 1] - 1, low[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cout << low[i] << (i == n ? '\n' : ' ');
    ans += (1LL) * (low[i] - m[i] - 1);
  }
  cout << ans << '\n';

  return 0;
}
