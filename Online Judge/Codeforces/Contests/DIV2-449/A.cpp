#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int l, r;
char c1, c2;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> s;
  for (int j = 1; j <= m; j++) {
    cin >> l >> r >> c1 >> c2;
    for (int i = l - 1; i <= r - 1; i++) {
      if (s[i] == c1) {
        s[i] = c2;
      }
    }
  }
  cout << s << '\n';

  return 0;
}