#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 5e6 + 5;

int n;
int a[N], ans;
bool vis[M];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!vis[a[i]]) {
      vis[a[i]] = 1;
      ans++;
    }
    for (int j = i - 1; j >= 1; j--) {
      if (a[j] == (a[i] | a[j])) break;
      a[j] = (a[i] | a[j]);
      if (!vis[a[j]]) {
        vis[a[j]] = 1;
        ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
