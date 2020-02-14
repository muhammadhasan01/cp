#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9 + 100;

int tc;
int n;
int a[N];

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
    int dif = 0;
    int maks = -INF, mins = INF;
    for (int i = 1; i < n; i++) {
      if (a[i] == -1) {
        if (a[i + 1] != -1) {
          maks = max(maks, a[i + 1]);
          mins = min(mins, a[i + 1]);
        }
        continue;
      }
      if (a[i + 1] == -1) {
        if (a[i] != -1) {
          maks = max(maks, a[i]);
          mins = min(mins, a[i]);
        }
        continue;
      }
      dif = max(dif, abs(a[i] - a[i + 1]));
    }
    int k = (maks + mins) >> 1;
    int m = max(max(maks - k, k - mins), dif);
    cout << m << " " << k << '\n';
  }

  return 0;
}
