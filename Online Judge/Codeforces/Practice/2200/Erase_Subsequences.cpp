#include <bits/stdc++.h>

using namespace std;

const int N = 400 + 5;
const int INF = 2e9;

int tc;
int n;
string s, t;
int suf[N][30];

bool check(const string& a, const string& b) {
  int la = a.size();
  int lb = b.size();
  vector<vector<int>> dp(la + 1, vector<int>(lb + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i <= la; i++) {
    for (int j = 0; j <= lb; j++) {
      int len = dp[i][j];
      if (len > n) continue;
      int cur_a, cur_b;
      if (i < la) cur_a = a[i] - 'a';
      if (j < lb) cur_b = b[j] - 'a';
      if (i < la && suf[len][cur_a] < INF) {
        dp[i + 1][j] = min(dp[i + 1][j], 1 + suf[len][cur_a]);
      }
      if (j < lb && suf[len][cur_b] < INF) {
        dp[i][j + 1] = min(dp[i][j + 1], 1 + suf[len][cur_b]);
      }
    }
  }
  return (dp[la][lb] < INF);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s >> t;
    n = s.length();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        suf[i][j] = INF;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        suf[i][j] = suf[i + 1][j];
      }
      suf[i][(int) (s[i] - 'a')] = i;
    }
    bool flag = false;
    for (int i = 0; i < (int) t.size(); i++) {
      if (check(t.substr(0, i), t.substr(i))) {
        flag = true;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
