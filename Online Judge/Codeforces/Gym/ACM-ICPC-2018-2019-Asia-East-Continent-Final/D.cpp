#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n, m;
int a[N], b[N];

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
      cin >> b[i];
    }
    puts(n <= m ? "Yes" : "No");
  }

  return 0;
}
