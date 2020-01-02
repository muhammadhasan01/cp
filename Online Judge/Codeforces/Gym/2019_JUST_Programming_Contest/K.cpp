#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    set<int> s, res;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      set<int> temp;
      for (auto e : s) {
        temp.insert(x | e);
      }
      temp.insert(x);
      for (auto e : temp) {
        res.insert(e);
      }
      s = temp;
    }
    cout << (int) res.size() << '\n';
  }

  return 0;
}
