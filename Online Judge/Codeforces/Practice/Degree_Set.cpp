#include <bits/stdc++.h>

using namespace std;

const int N = 3e2 + 5;
int n;
int d[N];
int cnt, last, tot;
vector<int> a, b;

inline void cz(bool u, int v) {
  if (!u) return;
  cnt++;
  for (int i = v + 1; i <= tot; i++) {
    a.push_back(v);
    b.push_back(i);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int i, l, r;
  for (i = 1; i <= n; i++) {
    cin >> d[i];
  }
  tot = d[n] + 1;
  for (i = 1, l = 1, r = n; i <= tot && l <= r; i++) {
    if (cnt + tot - i == d[r]) {
      r--;
      cz(1, i);
      last = 1;
    } else if (cnt == d[l]) {
      l++;
      cz(0, i);
      last = 0;
    } else {
      cz(last, i);
    }
  }
  for ( ; i <= tot; i++) {
    cz(last, i);
  }
  int len = a.size();
  cout << len << '\n';
  for (i = 0; i < len; i++) {
    cout << a[i] << " " << b[i] << '\n';
  }

  return 0;
}
