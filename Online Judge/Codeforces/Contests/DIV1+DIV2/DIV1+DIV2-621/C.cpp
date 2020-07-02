#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
string s;
long long dp[30][30];
long long suf[N][30];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  vector<long long> cnt(30);
  for (auto e : s) cnt[e - 'a']++;
  long long maks = 0;
  for (int i = 0; i < 26; i++) maks = max(maks, cnt[i]); 
  long long ans = max(maks, maks * (maks - 1) / 2);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) suf[i][j] = suf[i + 1][j];
    suf[i][s[i] - 'a']++;
  }
  for (int i = 0; i < n - 1; i++) {
    int alf = s[i] - 'a';
    for (int j = 0; j < 26; j++) {
      if (alf == j) continue;
      dp[alf][j] += suf[i + 1][j];
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j) continue;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';

  return 0;
}