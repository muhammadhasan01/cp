#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, k;
char a[N];
int par[N], sz[N];
int cntz[N][30];
char CC[N];
bool vis[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  if (sz[pu] < sz[pv]) swap(pu, pv);
  for (int j = 0; j < 26; j++) cntz[pu][j] += cntz[pv][j];
  par[pv] = pu;
}

int getz(int x) {
  int sum = 0;
  int maks = 0;
  for (int i = 0; i < 26; i++) {
    sum += cntz[x][i];
    maks = max(maks, cntz[x][i]);
  }
  return sum - maks;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
      for (int j = 0; j < 26; j++) {
        int alf = (a[i] - 'a');
        cntz[i][j] = (alf == j);
      }
    }
    for (int i = 1; i <= k; i++) {
      for (int j = i; j <= n; j += k) {
        merge(i, j);
      }
    }
    for (int i = 1; i <= n; i++) {
      merge(i, n - i + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (fpar(i) == i) {
        ans += getz(i);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}