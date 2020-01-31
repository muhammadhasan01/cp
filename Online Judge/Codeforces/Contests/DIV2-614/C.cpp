#include <bits/stdc++.h>

using namespace std;

const int Q = 1e5 + 5;

int n, q;
bool grn[3][Q];
int vis[3][Q];
int oc;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    int r, c;
    cin >> r >> c;
    r--;
    grn[r][c] ^= 1;
    if (grn[r][c]) {
      for (int j = c - 1; j <= c + 1; j++) {
        ++vis[(r ^ 1)][j];
        if (grn[(r ^ 1)][j]) oc++;
      }
    } else {
      for (int j = c - 1; j <= c + 1; j++) {
        --vis[(r ^ 1)][j];
        if (grn[(r ^ 1)][j]) oc--;
      }
    }
    cout << (oc == 0 ? "YES" : "NO") << '\n';
  }

  return 0;
}
