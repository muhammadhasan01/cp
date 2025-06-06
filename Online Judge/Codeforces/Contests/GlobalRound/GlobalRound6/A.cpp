#include <bits/stdc++.h>

using namespace std;

const int N = 500;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<string> v;
  for (int i = 0; i <= 96; i += 4) {
    if (i < 10) {
      string cur = "0" + to_string(i);
      v.push_back(cur);
    } else {
      v.push_back(to_string(i));
    }
  }

  cin >> n;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (s == "0") {
      cout << "red" << '\n';
      continue;
    }
    vector<int> cnt(15);
    for (auto e : s) {
      cnt[e - '0']++;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      sum += cnt[i] * i;
    }
    bool ok1 = false, ok2 = false;
    if (cnt[0] > 0) {
      ok1 = true;
    }
    for (auto e : v) {
      int x = e[0] - '0';
      int y = e[1] - '0';
      if (x == y && cnt[x] > 1) {
        ok2 = true;
        break;
      } else if (x != y && cnt[x] > 0 && cnt[y] > 0) {
        ok2 = true;
        break;
      }
    }
    cout << (sum % 3 == 0 && ok1 && ok2 ? "red" : "cyan") << '\n';
  }

  return 0;
}
