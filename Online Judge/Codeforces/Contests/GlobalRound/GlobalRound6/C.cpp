#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
int r, c;
int a[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c;
  if (r == 1 && c == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (r <= c) {
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        if (i == 1) {
          a[i][j] = j + 1;
        } else {
          a[i][j] = (j + 1) * (c + i);
        }
      }
    }
  } else {
    for (int j = 1; j <= c; j++) {
      for (int i = 1; i <= r; i++) {
        if (j == 1) {
          a[i][j] = i + 1;
        } else {
          a[i][j] = (i + 1) * (r + j);
        }
      }
    }
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << a[i][j] << (j == c ? '\n' : ' ');
    }
  }


  return 0;
}
