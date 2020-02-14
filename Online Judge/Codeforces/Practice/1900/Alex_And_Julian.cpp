#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int L = 64;

int n;
vector<int> deg[L];
long long a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long b;
    cin >> b;
    a[i] = b;
    int cnt = 0;
    while (b % 2 == 0) {
      b /= 2;
      cnt++;
    }
    deg[cnt].push_back(i);
  }
  int ans = 0, pos = 0;
  for (int i = 0; i < L; i++) {
    int len = deg[i].size();
    if (len > ans) {
      ans = len;
      pos = i;
    }
  }
  cout << n - ans << '\n';
  vector<bool> vis(n + 1);
  for (auto e : deg[pos]) vis[e] = 1;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}
