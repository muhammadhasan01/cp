#include <bits/stdc++.h>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> suf_1(n), suf_2(n);
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == '>') {
        suf_1[i] = suf_1[i + 1] + 1;
        suf_2[i] = 0;
      } else {
        suf_1[i] = 0;
        suf_2[i] = suf_2[i + 1] + 1;
      }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cout << n - cur - suf_2[i] << (i == n - 1 ? '\n' : ' ');
      if (suf_2[i] == 0) cur = i + 1;
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
      cout << suf_1[i] + cur + 1 << (i == n - 1 ? '\n' : ' ');
      if (suf_1[i] == 0) cur = i + 1;
    }
  }
  return 0;
}