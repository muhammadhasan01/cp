#include <bits/stdc++.h>

using namespace std;

const int N = 2e4;
const int INF = 1e9;

int tc;
int a, b, c;

int dp[N + 100][3];
vector<int> v[N + 100];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        v[i].push_back(j);
        if (j * j != i) v[i].push_back(i / j);
      }
    }
    sort(v[i].begin(), v[i].end());
  }

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c;
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= 2; j++) {
        dp[i][j] = INF;
      }
    }
    for (int i = 1; i <= N; i++) {
      dp[i][0] = min(dp[i][0], abs(a - i));
    }
    for (int i = 1; i <= N; i++) {
      for (auto e : v[i]) {
        dp[i][1] = min(dp[i][1], abs(b - i) + dp[e][0]);
      }
    }
    for (int i = 1; i <= N; i++) {
      for (auto e : v[i]) {
        dp[i][2] = min(dp[i][2], abs(c - i) + dp[e][1]);
      }
    }
    long long need = INF;
    for (int i = 1; i <= N; i++) {
      if (dp[i][2] < need) {
        need = dp[i][2];
      }
    }
    int _a = -1, _b = -1, _c = -1;
    for (int i = 1; i <= N; i++) {
      if (dp[i][2] == need) {
        _c = i;
        break;
      }
    }
    for (auto e : v[_c]) {
      if (dp[_c][2] == abs(c - _c) + dp[e][1]) {
        _b = e;
        break;
      }
    }
    for (auto e : v[_b]) {
      if (dp[_b][1] == abs(b - _b) + dp[e][0]) {
        _a = e;
        break;
      }
    }
    cout << need << '\n';
    cout << _a << " " << _b << " " << _c << '\n';
  }

  return 0;
}