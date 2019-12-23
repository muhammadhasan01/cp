#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, q, l, r;
int a[N];
int pre[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = (a[i] > a[i - 1] ? pre[i - 1] + 1 : 1);
  }
  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << (pre[r] - pre[l] == r - l ? "YA" : "TIDAK") << '\n';
  }

  return 0;
}
