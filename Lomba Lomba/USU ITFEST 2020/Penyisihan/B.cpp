#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int tc;
int n;
int p[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      for (int j = 2; j * j <= p[i]; j++) {
        if (p[i] % j == 0) {
          while (p[i] % j == 0) {
            cnt[i]++;
            p[i] /= j;
          }
        }
      }
      if (p[i] > 1) cnt[i]++;
    }
    int _xor = 0;
    for (int i = 1; i <= n; i++) {
      _xor ^= cnt[i];
    }
    cout << (_xor == 0 ? "YA" : "TIDAK") << " " << '\n';
  }

  return 0;
}