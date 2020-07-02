#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int M = 1e9 + 7;

string s;
int k;
short int dp[N + 5];
int c[N + 5][N + 5];
vector<int> store[10];

void compute() {
  c[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i - 1; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    c[i][i] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> k;
  int len = s.size();
  if (k == 0) {
    cout << 1 << '\n';
    return 0;
  } else if (k == 1) {
    cout << len - 1 << '\n';
    return 0;
  } else if (k > 5) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 1; i <= N; i++) {
    dp[i] = 1 + dp[__builtin_popcount(i)];
    store[dp[i]].push_back(i);
  }
  compute();
  vector<int> ones;
  for (int i = 0; i < len; i++) {
    if (s[i] == '1') {
      ones.push_back(len - i);
    }
  }
  int ans = 0;
  if (dp[(int) ones.size()] == k) ans++;
  for (auto e : store[k]) {
    int curcnt = 0;
    for (auto el : ones) {
      if (el - 1 < e - curcnt || e - curcnt < 0 || el - 1 < 0) break;
      ans = (ans + c[el - 1][e - curcnt]) % M;
      curcnt++;
    }
  }
  cout << (ans % M + M) % M << '\n';

  return 0;
}
