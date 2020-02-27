#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n, m;
int a[N], p[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> p[i];
    }
    sort(p + 1, p + 1 + m);
    for (int it = 1; it <= 200; it++) {
      for (int j = 1; j <= m; j++) {
        int pos = p[j];
        if (a[pos] > a[pos + 1]) swap(a[pos], a[pos + 1]);
      }
    }
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        flag = false;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }
  
  return 0;
}