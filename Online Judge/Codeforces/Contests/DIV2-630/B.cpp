#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n;
int a[N];
int ans[N];
int primez[N];
int vis[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 2; i <= N; i++) {
    if (primez[i] == 0) {
      for (int j = i; j <= N; j += i) {
        if (primez[j] == 0) primez[j] = i;
      }
    }
  }
  cin >> tc;
  while (tc--) {
    cin >> n;
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (vis[primez[a[i]]] == 0) {
        vis[primez[a[i]]] = ++cnt;
      }
      ans[i] = vis[primez[a[i]]];
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << (i == n ? '\n' : ' ');
    }
  }
  
  return 0;
}