#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, m;
vector<int> v[N];
int lenz[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> lenz[i];
    v[i].resize(lenz[i]);
    for (int j = 0; j < lenz[i]; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    map<int, int> mp;
    bool flag = true;
    for (int j = 0; j < lenz[i]; j++) {
      if (mp.count(-v[i][j]) > 0) {
        flag = false;
        break;
      }
      mp[v[i][j]] = 1;
    }
    if (flag) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';

  return 0;
}