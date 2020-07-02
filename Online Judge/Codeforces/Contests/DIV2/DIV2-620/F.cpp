#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 2e4 + 5;

int n, m, k;
int a[N][M];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }


  return 0;
}
