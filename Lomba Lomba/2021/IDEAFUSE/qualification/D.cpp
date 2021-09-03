#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

ll t[(N << 2) + 5], lz[(N << 2) + 5], ar[N + 5], dif[(N << 2) + 5];
int n, q;

ll calc(ll a, ll b, ll c) { // a + (a + c) + ... + (a + (b - 1) * c)
  return (2 * a + (b - 1) * c) * b / 2;
}

void build(int v, int s, int e) {
  if(s == e) {t[v] = ar[s]; return;}
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  t[v] = t[v << 1] + t[v << 1 | 1]; 
}

void push(int v, int s, int e) {
  if(!lz[v]) return;
  ll st = lz[v];
  int mid = (s + e) >> 1;
  lz[v << 1] += st;
  lz[v << 1 | 1] += (st + (mid + 1 - s) * dif[v]);
  t[v << 1] += calc(st, mid - s + 1, dif[v]);
  t[v << 1 | 1] += calc(st + (mid + 1 - s) * dif[v], e - mid, dif[v]);
  dif[v << 1] += dif[v];
  dif[v << 1 | 1] += dif[v];
  dif[v] = 0;
  lz[v] = 0;
} 

void upd(int v, int s, int e, int l, int r, int st) {
  if(l > e || r < s) return;
  if(l == s && r == e) {
    t[v] += calc(st, r - l + 1, 1);
    lz[v] += st;
    dif[v]++;
    return;
  }
  int mid = (s + e) >> 1;
  push(v, s, e);
  upd(v << 1, s, mid, l, min(r, mid), st);
  upd(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, st + max(l, 1 + mid) - l);
  t[v] = t[v << 1] + t[v << 1 | 1];
}

ll que(int v, int s, int e, int l, int r) {
  if(l > e || r < s) return 0;
  if(l == s && r == e) {
    return t[v];
  }
  int mid = (s + e) >> 1;
  push(v, s, e);
  return que(v << 1, s, mid, l, min(r, mid)) + que(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
}

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  build(1, 1, n);
  while(q--) {
    char type;
    int a, b;
    cin >> type;
    if(type == 'A') {
      cin >> a >> b;
      upd(1, 1, n, a, b, 1);
    } else {
      cin >> a;
      cout << que(1, 1, n, a, a) << '\n';
    } 
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}