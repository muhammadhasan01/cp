#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int MAXN = (1 << 20);
const int K = 25;
int pre[MAXN + 5];
int sp[MAXN + 5][K + 5];
int n;
int a[N];
set<int> v[N];

int query(int l, int r) {
  int k = pre[r - l + 1];
  return __gcd(sp[l][k], sp[r - (1 << k) + 1][k]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre[1] = 0;
  for (int i = 2; i <= MAXN; i++) {
    pre[i] = pre[i >> 1] + 1;
  }
  for (int i = 1; i <= n; i++) {
    sp[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      sp[i][j] = __gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int l1 = i + 1, r1 = n, pos1 = i;
    while (l1 <= r1) {
      int mid = (l1 + r1) / 2;
      if (query(i, mid) % a[i] == 0) {
        l1 = mid + 1;
        pos1 = mid;
      } else {
        r1 = mid - 1;
      }
    }
    int l2 = 1, r2 = i - 1, pos2 = i;
    while (l2 <= r2) {
      int mid = (l2 + r2) / 2;
      if (query(mid, i) % a[i] == 0) {
        r2 = mid - 1;
        pos2 = mid;
      } else {
        l2 = mid + 1;
      }
    }
    v[pos1 - pos2].insert(pos2);
  }
  for (int i = n - 1; i >= 0; i--) {
    int len = v[i].size();
    if (len == 0) continue;
    cout << len << " " << i << '\n';
    for (auto e : v[i]) {
      cout << e << " ";
    }
    cout << '\n';
    return 0;
  }

  return 0;
}
