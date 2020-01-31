#include <bits/stdc++.h>

using namespace std;

int n;
set<int> ans;
set<int, greater<int>> st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans.insert(x);
    st.insert(x);
  }
  while (!st.empty()) {
    int cur = *(st.begin());
    int cur_change = cur;
    while (cur_change > 0 && st.find(cur_change) != st.end()) cur_change /= 2;
    st.erase(cur);
    if (cur_change) {
      ans.erase(cur);
      ans.insert(cur_change);
      st.insert(cur_change);
    }
  }
  for (auto e : ans) cout << e << ' ';
  cout << '\n';

  return 0;
}
