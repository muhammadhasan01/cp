#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, m;
char a[N];
long long b[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    vector<long long> cnt(30);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long> dp(n + 5);
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      dp[x]++;
    }
    dp[n + 1] = 1;
    for (int i = n; i >= 1; i--) {
      dp[i] += dp[i + 1];
    }
    for (int i = 1; i <= n; i++) {
      cnt[a[i] - 'a'] += dp[i];
    }
    for (int i = 0; i < 26; i++) {
      cout << cnt[i] << (i == 25 ? '\n' : ' ');
    }
  }

  return 0;
}