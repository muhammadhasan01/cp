#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
pair<int, int> p[N];
int ans[N];
int deg[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    deg[p[i].first]++;
    deg[p[i].second]++;
  }
  int oc = 0, hm = 2;
  for (int i = 1; i < n; i++) {
    if (deg[p[i].first] == 1 || deg[p[i].second] == 1) {
      ans[i] = ++oc;
    }
  }
  for (int i = 1; i < n; i++) {
    if (ans[i] > 0) {
      cout << ans[i] - 1 << '\n';
    } else {
      cout << ++oc - 1 << '\n';
    }
  }

  return 0;
}