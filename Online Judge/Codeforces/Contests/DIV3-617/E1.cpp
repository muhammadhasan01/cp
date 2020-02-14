#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
char a[N];
int dp[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int cur = 1;
    int alf = a[i] - 'a';
    for (int j = alf + 1; j < 26; j++) {
      cur = max(cur, dp[j] + 1);
    }
    ans[i] = cur;
    dp[alf] = cur;
  }
  int res = *max_element(ans + 1, ans + 1 + n);
  if (res <= 2) {
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
      cout << ans[i] - 1;
    }
    cout << '\n';
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}
