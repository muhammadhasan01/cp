#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n, m;
string s[N], t[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i % n];
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i % m];
  }
  int q;
  cin >> q;
  while (q--) {
    int y;
    cin >> y;
    cout << s[y % n] + t[y % m] << '\n';
  }

  return 0;
}
