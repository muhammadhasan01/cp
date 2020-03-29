#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, c;
int a[N];
int cnt[N], res[N], pre[N], last[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + (a[i] == c);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == c) continue;
    cnt[a[i]] = max(0, cnt[a[i]] - (pre[i] - pre[last[a[i]]]));
    last[a[i]] = i;
    res[a[i]] = max(res[a[i]], ++cnt[a[i]]);
  }
  int resz = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == c) continue;
    resz = max(resz, res[a[i]]);
  }
  cout << pre[n] + resz << '\n';

  return 0;
}