#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
string v[N][3];
int ans[N];
int par[N];

void dismiss() {
  cout << "NO" << '\n';
  exit(0);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 1; i <= n; i++) {
    string s, t;
    cin >> s >> t;
    v[i][1] = s.substr(0, 3);
    v[i][2] = s.substr(0, 2) + t.substr(0, 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (v[i][1] == v[j][1] && v[i][2] == v[j][2]) dismiss();
      if (v[i][1] == v[j][2]) {
        par[j] = i;
      }
      if (v[i][2] == v[j][1]) {
        par[i] = j;
      }
    }
  }
  map<string, vector<int>> mp;
  map<string, int> vis;
  for (int i = 1; i <= n; i++) {
    mp[v[i][1]].push_back(i);
  }
  for (auto e : mp) {
    int len = (int) e.second.size();
    if (len == 1) continue;
    for (auto el : e.second) {
      ans[el] = 2;
      vis[v[el][2]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] != 2) continue;
    int j = par[i];
    while (1) {
      if (ans[j] == 2) break;
      if (vis.count(v[j][2])) dismiss();
      vis[v[j][2]] = 1;
      ans[j] = 2;
      j = par[j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 2) continue;
    ans[i] = 1;
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    cout << v[i][ans[i]] << '\n';
  }

  return 0;
}