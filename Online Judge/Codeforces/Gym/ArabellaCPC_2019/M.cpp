#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  vector<int> cnt(30);
  for (auto e : s) {
    cnt[e - 'a']++;
  }
  for (int i = 0; i < 25; i++) {
    cnt[i + 1] += (cnt[i] / 2);
    cnt[i] &= 1;
  }
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < cnt[i]; j++) {
      cout << char(i + int('a'));
    }
  }
  cout << '\n';

  return 0;
}
