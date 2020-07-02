#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int n, m;
int ans = 2e9 + 5;
int a[N], b[N];
int la, lb;
pair<int, int> oa[2 * N], ob[2 * N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int c = 0, last = a[1];
  for (int i = 1; i <= n; i++) {
    if (a[i] == last) {
      c++;
    } else {
      oa[++la] = {c, last};
      last = a[i];
      c = 1;
    }
  }
  oa[++la] = {c, last};
  c = 0, last = b[1];
  for (int i = 1; i <= n; i++) {
    if (b[i] == last) {
      c++;
    } else {
      ob[++lb] = {c, last};
      last = b[i];
      c = 1;
    }
  }
  ob[++lb] = {c, last};
  for (int i = lb + 1; i <= 2 * lb - 1; i++) {
    ob[i] = ob[i - lb];
  }
  for (int i = 1; i <= 2 * lb - 1; i++) {
    if (la + i - 1 > 2 * lb - 1) break;
    bool flag = true;
    int cur = ob[i].second - oa[1].second;
    cur = (cur % m + m) % m;
    for (int j = 1; j <= la; j++) {
      if (oa[j].first != ob[j + i - 1].first) {
        flag = false;
        break;
      }
      int dif = ob[j + i - 1].second - oa[j].second;
      dif = (dif % m + m) % m;
      if (dif != cur) {
        flag = false;
        break;
      }
    }
    if (flag) ans = min(ans, cur);
  }
  cout << ans << '\n';

  return 0;
}
