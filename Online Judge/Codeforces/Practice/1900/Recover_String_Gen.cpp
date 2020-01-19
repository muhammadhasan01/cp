#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string s;
int n;
long long a[2][2];
long long suf[N][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  int n = s.length();
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1) for (int j = 0; j < 2; j++) suf[i][j] = suf[i + 1][j];
    suf[i][s[i] - '0']++;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '0') {
      a[0][0] += suf[i + 1][0];
      a[0][1] += suf[i + 1][1];
    } else {
      a[1][1] += suf[i + 1][1];
      a[1][0] += suf[i + 1][0];
    }
  }
  cout << a[0][0] << " " << a[0][1] << " " << a[1][0] << " " << a[1][1] << '\n';

  return 0;
}
