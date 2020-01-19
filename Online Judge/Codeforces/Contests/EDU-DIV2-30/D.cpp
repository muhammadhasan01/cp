#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int ans[N];

void f(int l, int r, int k) {
  if (k == 0) {
    for (int i = l; i < r; i++) ans[i] = i + 1;
    return;
  }
  if (r - l == 1) {
    cout << -1 << '\n';
    exit(0);
  }
  int mid = (l + r) >> 1;
  if (k == 2) {
    for (int i = l; i < mid; i++) ans[i] = i + 1 + r - mid;
    for (int i = mid; i < r; i++) ans[i] = i - mid + l + 1;
    return;
  }
  k -= 2;
  int lef = k / 2;
  if (lef % 2) --lef;
  int rig = k - lef;
  f(l, mid, lef);
  f(mid, r, rig);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  if (k % 2 == 0) {
    cout << -1 << '\n';
    return 0;
  }
  f(0, n, k - 1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}
