#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int s[N];

int get() {
  int ret = s[1] ^ s[2];
  vector<int> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && st.back() < s[i]) st.pop_back();
    st.push_back(s[i]);
    int len = st.size();
    if (len >= 2) ret = max(ret, st[len - 1] ^ st[len - 2]);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int ans = get();
  reverse(s + 1, s + 1 + n);
  ans = max(ans, get());
  cout << ans << '\n';

  return 0;
}
