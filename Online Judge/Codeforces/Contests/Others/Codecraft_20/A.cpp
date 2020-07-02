#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n, m;
int a[N];

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
    for (int i = 2; i <= n; i++) {
      if (a[1] < m) {
        a[1] += min(a[i], m - a[1]);
      }
    }
    cout << a[1] << '\n';
  }

  return 0;
}