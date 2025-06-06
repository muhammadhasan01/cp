#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  char last = s[0];
  string cur = "";
  cur += last;
  for (int i = 0; i < n; i++) {
    if (s[i] == last) continue;
    last = s[i];
    cur += last;
  }
  set<char> st;
  int ans = 0;
  int m = cur.size();
  for (int i = 0; i < m; i++) {
    if (isupper(cur[i])) {
      st.clear();
      continue;
    }
    st.insert(cur[i]);
    ans = max(ans, (int) st.size());
  }
  cout << ans << '\n';

  return 0;
}
