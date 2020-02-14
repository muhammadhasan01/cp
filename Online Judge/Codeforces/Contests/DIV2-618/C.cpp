#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 35;

int n;
int a[N];
int cnt[M];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 30; j >= 0; j--) {
      bool b = a[i] & (1 << j);
      if (b) cnt[j]++;
    }
  }
  int pos = 1;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 30; j >= 0; j--) {
      bool b = a[i] & (1 << j);
      if (b && cnt[j] == 1) {
        cur |= (1 << j);
      }
    }
    if (cur > res) {
      res = cur;
      pos = i;
    }
  }
  swap(a[1], a[pos]);
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
