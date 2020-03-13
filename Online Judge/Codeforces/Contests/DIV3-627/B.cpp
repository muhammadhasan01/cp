#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int tc;
int n;
int a[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      v[x].push_back(i);
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      int len = v[i].size();
      if (len <= 1) continue;
      if (len == 2) {
        if (v[i][1] - v[i][0] > 1) {
          flag = true;
          break;
        }
        continue;
      }
      flag = true;
      break;
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}