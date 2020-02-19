#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int par[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  if (k - 1 < (n + k - 1) / k) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    par[i] = 1;
  }
  vector<pair<int, int>> ans;
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    int cur = i;
    while (cnt < n) {
      if (par[cur] == cur) par[cur]++;
      ans.push_back({cur, par[cur]});
      cnt++;
      cur = par[cur]++;
      if (cur == i && par[cur] > k) break;
    }
  }
  cout << "YES" << '\n';
  for (auto e : ans) {
    cout << e.first << " " << e.second << '\n';
  }

  return 0;
}