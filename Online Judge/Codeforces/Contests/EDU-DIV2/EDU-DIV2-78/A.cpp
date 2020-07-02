#include <bits/stdc++.h>

using namespace std;

int tc;
string p, h;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> p >> h;
    vector<int> cnt(30);
    for (auto e : p) {
      cnt[e - 'a']++;
    }
    int l1 = p.size(), l2 = h.size();
    if (l1 > l2) {
      cout << "NO" << '\n';
      continue;
    }
    bool flag = false;
    for (int i = 0; i < l2; i++) {
      vector<int> temp(30);
      for (int j = i; j <= i + l1 - 1; j++) {
        if (j >= l2) break;
        temp[h[j] - 'a']++;
      }
      if (temp == cnt) {
        flag = true;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
