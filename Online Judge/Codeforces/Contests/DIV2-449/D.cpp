#include <bits/stdc++.h>

using namespace std;

int n, m, c;
vector<int> v, w;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> c;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (x <= c / 2) {
      if (v.empty()) {
        v.push_back(x);
        cout << 1 << endl;
      } else {
        auto it = upper_bound(v.begin(), v.end(), x);
        if (it == v.end()) {
          v.push_back(x);
          cout << v.size() << endl;
        } else {
          *it = x;
          cout << it - v.begin() + 1 << endl;
        }
      }
    } else {
      x = c - x;
      if (w.empty()) {
        w.push_back(x);
        cout << n << endl;
      } else {
        auto it = upper_bound(w.begin(), w.end(), x);
        if (it == w.end()) {
          w.push_back(x);
          cout << n - w.size() + 1 << endl;
        } else {
          *it = x;
          cout << n - (it - w.begin() + 1) + 1 << endl;
        }
      }
    }
    if ((int) v.size() + (int) w.size() == n) return 0;
  }

  return 0;
}