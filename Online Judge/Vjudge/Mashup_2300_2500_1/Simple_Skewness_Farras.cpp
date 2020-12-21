#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n;
ll ar[N + 5];
ll pre[N + 5]; 

ld f(int m, int idx, int lul) {
  ll sum = pre[idx] - pre[idx - m - 1] + pre[n] - pre[n - m];
  if (lul == 2) sum += ar[idx + 1];
  ll cnt = (lul == 1 ? 2 * m + 1 : 2 * m + 2);
  ld mean = ((ld)sum) / ((ld)cnt);
  ld median = (lul == 1 ? (ld)ar[idx] : ((ld)(ar[idx] + ar[idx + 1])) / ((ld)2));
  return mean - median;
}

ld ternary_search(int l, int r, int idx, int& cnt, int lul) {
  while (r - l >= 3) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    ld f1 = f(m1, idx, lul);
    ld f2 = f(m2, idx, lul);
    if (f1 < f2) {
      l = m1 + 1;
    } else {
      r = m2;
    }
  }
  ld mx = -1e18;
  for (; l <= r; l++) {
    if (f(l, idx, lul) > mx) {
      cnt = l;
      mx = f(l, idx, lul);
    }
  }
  return mx;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  sort(ar + 1, ar + n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = ar[i] + pre[i - 1];
  }
  //ganjil
  ld mx1 = -1e18;
  int cnt1;
  int mid1;
  for (int i = 1; i <= n; i++) {
    int l = 0;
    int r = min(i - 1, n - i);
    int k;
    ld tmp = ternary_search(l, r, i, k, 1);
    if (tmp > mx1) {
      mid1 = i;
      cnt1 = k;
      mx1 = tmp;
    }
  }
  //genap
  ld mx2 = -1e18;
  int cnt2;
  int mid2;
  for (int i = 1; i < n; i++) {
    int l = 0;
    int r = min(i - 1, n - i - 1);
    int k;
    ld tmp = ternary_search(l, r, i, k, 2);
    if (tmp > mx2) {
      mid2 = i;
      cnt2 = k;
      mx2 = tmp;
    }
  }

  if (mx1 > mx2) {
    cout << 2 * cnt1 + 1 << '\n';
    for (int i = 1; i <= cnt1; i++) {
      cout << ar[mid1 - i] << ' ';
    }
    cout << ar[mid1] << ' ';
    for (int i = n; i >= n - cnt1 + 1; i--) {
      cout << ar[i] << ' ';
    }
  } else {
    cout << 2 * cnt2 + 2 << '\n';
    for (int i = 1; i <= cnt2; i++) {
      cout << ar[mid2 - i] << ' ';
    }
    cout << ar[mid2] << ' ' << ar[mid2 + 1] << ' ';
    for (int i = n; i >= n - cnt2 + 1; i--) {
      cout << ar[i] << ' ';
    }
  }
  cout << '\n';
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