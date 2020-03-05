#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m;
long long p;
long long a[N], b[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= p;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i] %= p;
  }
  int p1 = 0, p2 = 0;
  while (1) {
    if (a[p1] != 0 && b[p2] != 0) {
      cout << p1 + p2 << '\n';
      return 0;
    }
    if (p1 < n && a[p1] == 0) p1++;
    if (p2 < m && b[p2] == 0) p2++;
    if (p1 == n && p2 == m) break;
  }

  return 0;
}