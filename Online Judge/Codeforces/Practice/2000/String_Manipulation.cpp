#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k, len, q;
string s;
char a[N];
int bit[N][30];
bool vis[N];

void add(int x, int p, int val) {
  for ( ; x <= n; x += x & -x) {
    bit[x][p] += val;
  }
}

int get(int x, int p) {
  int ret = 0;
  for ( ; x > 0; x -= x & -x) {
    ret += bit[x][p];
  }
  return ret;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k >> s;
  len = s.size();
  n = k * len;
  for (int i = 1; i <= n; i++) {
    a[i] = s[(i - 1) % len];
    add(i, (int) (a[i] - 'a'), 1);
  }
  cin >> q;
  while (q--) {
    int pos;
    char x;
    cin >> pos >> x;
    int id = x - 'a';
    int l = 1, r = n, best = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(mid, id) >= pos) {
        r = mid - 1;
        best = mid;
      } else {
        l = mid + 1;
      }
    }
    add(best, id, -1);
    vis[best] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    cout << a[i];
  }
  cout << '\n';

  return 0;
}