#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  set<int> res, s;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    set<int> temp;
    for (auto e : s) {
      temp.insert((e | x));
    }
    temp.insert(x);
    for (auto e : temp) {
      res.insert(e);
    }
    s = temp;
  }
  cout << (int) res.size() << '\n';

  return 0;
}
