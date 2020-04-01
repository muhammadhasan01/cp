#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;

int k;
int a[N][N];
int dp[N][N];

void solve() {
  if (k == 0) {
    cout << 1 << " " << 1 << '\n';
    cout << 1 << '\n';
    return;
  }
  int mama = (1 << 18) - 1;
  int makz = (1 << 17) - 1;
  int hmmz = (1 << 17);
  int req = makz - k;
  a[1][1] = mama;
  a[1][2] = makz;
  a[1][3] = req;
  a[2][1] = hmmz;
  a[2][2] = mama;
  a[2][3] = makz;
  cout << 2 << " " << 3 << '\n';
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << a[i][j] << (j == 3 ? '\n' : ' ');
    }
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k;
  solve();

  return 0;
}