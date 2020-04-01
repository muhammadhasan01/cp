#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 100;
const int N = 1e5 + 5;

int tc;
long long n, k;
string beginz = "What are you doing at the end of the world? Are you busy? Will you save us?";
string x = "What are you doing while sending \"";
string y = "\"? Are you busy? Will you send \"";
long long lenz, lenx, leny;
long long dp[N];

char solve(long long n, long long k) {
  if (k > dp[n]) return '.';
  if (n == 1) return beginz[k - 1];
  if (k <= lenx) return x[k - 1];
  k -= lenx;
  if (k > dp[n - 1]) {
    k -= dp[n - 1];
    if (k <= leny) return y[k - 1];
    k -= leny;
    if (k > dp[n - 1]) {
      k -= dp[n - 1];
      if (k == 1) return '\"';
      if (k >= 2) return '?';
    }
  }
  return solve(n - 1, k);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  lenz = beginz.size();
  lenx = x.size();
  leny = y.size();
  dp[1] = lenz;
  for (int i = 2; i < N; i++) {
    dp[i] = min(INF, 2 * dp[i - 1] + lenx + leny + 2);
  }
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    n++;
    cout << solve(n, k);
  }
  cout << '\n';

  return 0;
}