#include <bits/stdc++.h>

using namespace std;

int tc;
int n, d;
int a[105];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= d; i++) {
      for (int i = 2; i <= n; i++) {
        if (a[i] > 0) {
          a[i - 1]++;
          a[i]--;
          break;
        }
      }
    }
    cout << a[1] << '\n';
  }

  return 0;
}