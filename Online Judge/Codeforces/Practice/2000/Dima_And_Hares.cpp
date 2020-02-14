#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

int n;
int a[N], b[N], c[N];
int pre[N], suf[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  pre[1] = a[1];
  for (int i = 2; i <= n; i++) {
    int dif = c[i - 1] - b[i - 1];
    int sum = b[i - 1];
    for (int j = i - 2; j >= 1; j--) {
      pre[i] = max(pre[i], pre[j] + a[i] + sum + dif);
      dif = max(dif, c[j] - b[j]);
      sum += b[j];
    }
    pre[i] = max(pre[i], a[i] + sum);
  }
  suf[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    int dif = c[i + 1] - b[i + 1];
    int sum = b[i + 1];
    for (int j = i + 2; j <= n; j++) {
      suf[i] = max(suf[i], suf[j] + a[i] + sum + dif);
      dif = max(dif, c[j] - b[j]);
      sum += b[j];
    }
    suf[i] = max(suf[i], a[i] + sum);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, pre[i] + suf[i] - a[i]);
  }
  cout << ans << '\n';

  return 0;
}
