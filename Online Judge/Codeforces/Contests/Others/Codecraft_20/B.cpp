#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
string s;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    string k = s;
    reverse(k.begin(), k.end());
    int midx = 1;
    string mini = s;
    char minz = 'z';
    for (auto e : s) minz = min(minz, e);
    for (int i = 1; i < n - 1; i++) {
      if (s[i] == minz) {
        bool flag = false;
        bool cont = false;
        int cur = 0;
        for (int j = i; j < n; j++, cur++) {
          if (s[j] < mini[cur]) {
            flag = true;
            break;
          } else if (s[j] > mini[cur]) {
            cont = true;
            break;
          }
        }
        if (cont) continue;
        int len = n - i;
        string pref = s.substr(0, i);
        if (len % 2 == 1) {
          reverse(pref.begin(), pref.end());
        }
        if (flag) {
          midx = i + 1;
          mini = s.substr(i) + pref;
          continue;
        }
        for (int j = 0; j < i; j++, cur++) {
          if (pref[j] < mini[cur]) {
            flag = true;
            break;
          } else if (pref[j] > mini[cur]) {
            cont = true;
            break;
          }
        }
        if (cont) continue;
        if (flag) {
          midx = i + 1;
          mini = s.substr(i) + pref;
          continue;
        }
      }
    }
    if (k < mini) {
      mini = k;
      midx = n;
    }
    cout << mini << '\n';
    cout << midx << '\n';
  }
  
  return 0;
}