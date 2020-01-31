#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long>> matrix;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

int tc;
long long n, m;
long long dp[N];

matrix mul(matrix a, matrix b) {
  matrix c(2, vector<long long>(2, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][j] += ((a[i][k] % M) * (b[k][j] % M));
        c[i][j] %= M;
      }
    }
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    m %= M;
    if (n == 1) {
      cout << m << '\n';
      continue;
    }
    matrix v = {{0, 1}, {m - 1, m - 1}};
    matrix I = {{1, 0}, {0, 1}};
    n--;
    while (n) {
      if (n & 1) I = mul(I, v);
      n >>= 1;
      v = mul(v, v);
    }
    long long res1 = ((I[0][0] % M) * m) % M;
    long long res2 = ((I[0][1] % M) * m) % M;
    res2 = (res2 * m) % M;
    res1 = (res1 + res2) % M;
    cout << (res1 % M + M) % M << '\n';
  }

  return 0;
}
