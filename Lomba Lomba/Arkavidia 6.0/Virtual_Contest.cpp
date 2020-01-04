#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const int M = 3e4 + 5;
const int K = N + M;

int n, qr;
int a[N];
int bit[K], ord[K], rev[K], len;
pair<int, int> q[M];
map<int, int> mp;

void add(int x) {
  for ( ; x < K; x += x & -x) bit[x]++;
}

int get(int x) {
  int ret = 0;
  for ( ; x > 0; x -= x & -x) ret += bit[x];
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ord[++len] = a[i];
  }
  cin >> qr;
  for (int i = 1; i <= qr; i++) {
    cin >> q[i].first >> q[i].second;
    if (q[i].first == 1) {
      ord[++len] = q[i].second;
    }
  }
  sort(ord + 1, ord + 1 + len);
  for (int i = 1; i <= len; i++) {
    if (mp.count(ord[i]) == 0) {
      mp[ord[i]] = i;
      rev[i] = ord[i];
    }
  }
  int rank = 0;
  for (int i = 1; i <= n; i++) {
    add(mp[a[i]]);
    rank++;
  }
  for (int i = 1; i <= qr; i++) {
    if (q[i].first == 1) {
      add(mp[q[i].second]);
      rank++;
    } else {
      int l = 1, r = len, ans = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(mid) >= rank - q[i].second + 1) {
          r = mid - 1;
          ans = mid;
        } else {
          l = mid + 1;
        }
      }
      cout << rev[ans] << '\n';
    }
  }

  return 0;
}
