#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  vector<int> v, w;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(') {
      v.push_back(i);
    } else {
      w.push_back(i);
    }
  }
  reverse(v.begin(), v.end());
  vector<vector<int>> ans;
  for (int it = 1; it <= n; it++) {
    vector<int> res;
    for (int i = 1; i <= n; i++) {
      if (v.empty()) break;
      if (w.empty()) break;
      if (v.back() < w.back()) {
        res.push_back(v.back());
        res.push_back(w.back());
        v.pop_back();
        w.pop_back();
      } else {
        break;
      }
    }
    if (res.empty()) break;
    sort(res.begin(), res.end());
    ans.push_back(res);
  }
  cout << ans.size() << '\n';
  for (auto& e : ans) {
    cout << e.size() << '\n';
    for (auto& el : e) cout << el << " ";
    cout << '\n';
  }

  return 0;
}