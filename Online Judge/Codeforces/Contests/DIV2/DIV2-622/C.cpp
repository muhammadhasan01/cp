#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n;
long long a[N], b[N];
long long ans[N];


int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long res = -1;
  for (int i = 1; i <= n; i++) {
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = a[i];
    }
    cur += b[i];
    for (int j = i + 1; j <= n; j++) {
      if (b[j] > b[j - 1]) b[j] = b[j - 1];
      cur += b[j];
    }
    for (int j = i - 1; j >= 1; j--) {
      if (b[j] > b[j + 1]) b[j] = b[j + 1];
      cur += b[j];
    }
    if (cur > res) {
      res = cur;
      for (int i = 1; i <= n; i++) {
        ans[i] = b[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}