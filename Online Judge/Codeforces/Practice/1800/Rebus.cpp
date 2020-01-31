#include <bits/stdc++.h>

using namespace std;

string s;

void dismiss() {
  cout << "Impossible" << '\n';
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  getline(cin, s);
  s = "+ " + s;
  vector<bool> v;
  bool cond;
  int cur = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '+') {
      cond = 1;
    } else if (s[i] == '-') {
      cond = 0;
    } else if (s[i] == '?') {
      v.push_back(cond);
    } else if (isdigit(s[i])) {
      cur = cur * 10 + (s[i] - '0');
    }
  }
  int pos = 0, neg = 0;
  for (auto e : v) {
    if (e) pos++;
    else neg++;
  }
  if (pos * cur - neg < cur || pos - neg * cur > cur) dismiss();
  int dif = (pos * cur - neg) - cur;
  int len = v.size();
  vector<int> ans(len);
  for (int i = 0; i < len; i++) {
    if (v[i]) {
      ans[i] = cur;
    } else {
      ans[i] = 1;
    }
  }
  for (int i = 0; i < len; i++) {
    if (!v[i]) continue;
    if (cur - 1 < dif) {
      ans[i] = 1;
      dif -= (cur - 1);
    } else {
      ans[i] = cur - dif;
      dif = 0;
    }
    if (dif == 0) break;
  }
  for (int i = 0; i < len; i++) {
    if (v[i]) continue;
    if (cur - 1 < dif ) {
      ans[i] = cur;
      dif -= cur - 1;
    } else {
      ans[i] = 1 + dif;
      dif = 0;
    }
    if (dif == 0) break;
  }
  bool flag = false;
  cout << "Possible" << '\n';
  for (int i = 0; i < len; i++) {
    if (v[i]) {
      if (i > 0) cout << "+ ";
    } else {
      cout << "- ";
    }
    cout << ans[i] << " ";
  }
  cout << "= " << cur << '\n';

  return 0;
}
