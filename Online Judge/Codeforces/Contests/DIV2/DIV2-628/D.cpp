#include <bits/stdc++.h>

using namespace std;

long long u, v;
vector<long long> ans;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> u >> v;
  if (u > v || abs(u - v) & 1) {
    cout << -1 << '\n';
    return 0;
  }  
  if (v == 0) {
    cout << 0 << '\n';
    return 0;
  }
  if (u == v) {
    cout << 1 << '\n';
    cout << u << '\n';
    return 0;
  }
  if ((u & ((v - u) / 2)) == 0) {
    ans.push_back(u ^ ((v - u) / 2));
    ans.push_back((v - u) / 2);
  } else {
    ans.push_back(u);
    for (int i = 0; i < 2; i++) ans.push_back((v - u) / 2);
  }
  cout << ans.size() << '\n';
  for (auto e : ans) cout << e << ' ';

  return 0;
}