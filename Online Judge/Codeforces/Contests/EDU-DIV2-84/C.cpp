#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n, m, k;
pair<int, int> p[N];
pair<int, int> q[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 1; i <= k; i++) {
    cin >> q[i].first >> q[i].second;
  }
  if (m == 1) {
    cout << 2 * n << '\n';
    for (int i = 1; i <= n; i++) {
      cout << "U";
    }
    for (int i = 1; i <= n; i++) {
      cout << "D";
    }
  } else if (n == 1) {
    cout << 2 * m << '\n';
    for (int i = 1; i <= m; i++) {
      cout << "L";
    }
    for (int i = 1; i <= m; i++) {
      cout << "R";
    }
  } else if (n + m - 2 + n * (m - 1) + n - 1 <= 2 * n * m) {
    cout << n + m - 2 + n * (m - 1) + n - 1 << '\n';
    for (int i = 1; i <= n - 1; i++) cout << "U";
    for (int i = 1; i <= m - 1; i++) cout << "L";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
          cout << (i & 1 ? "R" : "L");
        }
        if (i != n) cout << "D";
    }
  } else if (n + m - 2 + (n - 1) * m + m - 1 <= 2 * n * m) {
    cout << n + m - 2 + (n - 1) * m + m - 1 << '\n';
    for (int i = 1; i <= n - 1; i++) cout << "U";
    for (int i = 1; i <= m - 1; i++) cout << "L";
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n - 1; i++) {
          cout << (j & 1 ? "D" : "U");
        }
        if (j != m) cout << "R";
    }
  }
  cout << '\n';

  return 0;
}