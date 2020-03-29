#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = (1 << 18);
const int L = 18;

int n, q;
int a[N];
int sp[K][L];
int pre[K];
unordered_map<int, long long> mp;

int get(int l, int r) {
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
    sp[i][0] = a[i];
  }
  pre[1] = 0;
  for (int i = 2; i < K; i++) {
    pre[i] = pre[i >> 1] + 1;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      sp[i][j] = __gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int j = n;
    while (j >= i) {
      int cur = get(i, j);
      int l = i, r = j, at = j;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(i, mid) == cur) {
          r = mid - 1;
          at = mid;
        } else {
          l = mid + 1;
        }
      }
      mp[cur] += (1LL) * (j - at + 1);
      j = at - 1;
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    cout << mp[x] << '\n';
  }

  return 0;
}