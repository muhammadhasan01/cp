#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct edge {
  bool in;
  int idx;
  long long w;
  bool operator < (edge& x) {
    if (w == x.w) return (in > x.in);
    return (w < x.w);
  }
};

int n, m;
edge p[N];
int rem[N];
pair<int, int> ans[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> p[i].w >> p[i].in;
    p[i].idx = i;
  }
  sort(p + 1, p + 1 + m);
  long long inc = 0, not_inc = 0;
  int q = 0;
  for (int i = 1; i <= m; i++) {
    if (p[i].in) {
      ans[p[i].idx] = {1, ++inc + 1};
    } else {
      ++not_inc;
      if ((inc - 1) * inc < 2 * not_inc) {
        cout << -1 << '\n';
        return 0;
      }
      rem[++q] = p[i].idx;
    }
  }
  int cnt = 0;
  for (int i = 3; i <= n; i++) {
    if (cnt == q) break;
    for (int j = 2; j < i; j++) {
      if (cnt == q) break;
      int id = rem[++cnt];
      ans[id] = {j, i};
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }

  return 0;
}
