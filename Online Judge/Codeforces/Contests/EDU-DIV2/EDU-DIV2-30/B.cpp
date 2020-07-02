#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
string s;
int pre[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  s = "#" + s + "#";
  for (int i = 1; i <= n; i++) {
    pre[i] += (s[i] == '1' ? 1 : -1) + pre[i - 1];
  }
  map<int, int> mp;
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    if (!mp.count(pre[i])) mp[pre[i]] = i;
    else {
      ans = max(ans, i - mp[pre[i]]);
    }
  }
  mp.clear();
  for (int i = 0; i <= n; i += 2) {
    if (!mp.count(pre[i])) mp[pre[i]] = i;
    else {
      ans = max(ans, i - mp[pre[i]]);
    }
  }
  cout << ans << '\n';

  return 0;
}
