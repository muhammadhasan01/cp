#include <bits/stdc++.h>

using namespace std;

const int K = (1 << 9) + 5;

int k;
char a[K][K];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  a[1][1] = '+';
  a[1][2] = '+';
  a[2][1] = '*';
  a[2][2] = '+';
  for (int t = 2; t <= 9; t++) {
    for (int i = 1; i <= (1 << (t - 1)); i++) {
      for (int j = (1 << (t - 1)) + 1; j <= (1 << t); j++) {
        a[i][j] = a[i][j - (1 << (t - 1))];
      }
    }
    for (int i = (1 << (t - 1)) + 1; i <= (1 << t); i++) {
      for (int j = 1; j <= (1 << (t - 1)); j++) {
        a[i][j] = a[i - (1 << (t - 1))][j];
      }
    }
    for (int i = (1 << (t - 1)) + 1; i <= (1 << t); i++) {
      for (int j = (1 << (t - 1)) + 1; j <= (1 << t); j++) {
        a[i][j] = a[i - (1 << (t - 1))][j - (1 << (t - 1))];
        a[i][j] = (a[i][j] == '+' ? '*' : '+');
      }
    }
  }
  cin >> k;
  for (int i = 1; i <= (1 << k); i++) {
    for (int j = 1; j <= (1 << k); j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }

  return 0;
}
