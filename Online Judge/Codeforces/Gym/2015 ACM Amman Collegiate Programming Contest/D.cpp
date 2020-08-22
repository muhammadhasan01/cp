#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
const int N = 1e5;

int n, k;
string s;
int ans[N + 5], lol[N + 5];
int t[4 * N + 20];

void upd(int v, int s, int e, int pos, int val) {
  if(s == e && s == pos) {t[v] = val; return;}
  int mid = (s + e) >> 1;
  if(pos <= mid)
    upd(v << 1, s, mid, pos, val);
  else
    upd(v << 1 | 1, mid + 1, e, pos, val);
  t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int que(int v, int s, int e, int l, int r) {
  if(l > r || l > e || r < s) return INF;
  if(l <= s && e <= r) return t[v];
  int mid = (s + e) >> 1;
  int a = que(v << 1, s, mid, l, r);
  int b = que(v << 1 | 1, mid + 1, e, l, r);
  return min(a, b);
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i <= n; i++) ans[i] = lol[i] = 0;
  for(int i = 0; i <= 4 * n; i++) t[i] = INF; 
  cin >> s;
  for(int i = 0; i < n - 1; i++) {
    lol[i + 1] = (s[i] != s[i + 1]);
  }
  if(n == 1 || k == 1) {
    cout << n - 1 << '\n';
    return;
  }
  int pos = 0;
  for(int i = 1; i < n; i++) {
    if(i < k - 1) {
      if(pos == 0 && lol[i] == 1) {
        ans[i] = i;
      } else {
        ans[i] = 0;
      }
    } else if(i == k - 1) {
      if(lol[i] == 0) ans[i] = 0;
      else if(pos == 0) ans[i] = i;
      else ans[i] = 0;
    } else {
      int l = i - k + 2;
      ans[i] = 1 + ans[i - 1];
      if(lol[i] == 1) {
        if(pos < l) {
          ans[i] = min(ans[i], 1 + ans[i - 1]);
        } else if(pos == l) {
          ans[i] = min(ans[i], 1 + ans[l - 2]);
        } else {
          int mn = que(1, 1, n - 1, l - 2, pos - 2);
          ans[i] = min(ans[i], 1 + mn);
          // ans[i] = min(ans[i], 1 + ans[pos - 2]);
        }
      } else {
        int mn = que(1, 1, n - 1, l - 2, i - 1);
        ans[i] = min(ans[i], 1 + mn);
        // ans[i] = min(ans[i], 1 + ans[l - 2]);
      }
    }
    upd(1, 1, n - 1, i, ans[i]);
    if(lol[i] == 0) pos = i;
  }
  // for(int i = 1; i < n; i++) {
  //   cerr << i << ' ' << ans[i] << ' ' << lol[i] << ":D\n";
  // }
  cout << ans[n - 1] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}