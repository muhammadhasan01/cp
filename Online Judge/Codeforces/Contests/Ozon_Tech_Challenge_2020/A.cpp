#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int tc;
int a[N], b[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    } 
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
      cout << a[i] << (i == n ? '\n' : ' ');
    }
    for (int i = 1; i <= n; i++) {
      cout << b[i] << (i == n ? '\n' : ' ');
    }
  }

  return 0;
}