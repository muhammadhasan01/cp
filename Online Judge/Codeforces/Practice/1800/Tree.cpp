#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, id;
map<int, int> m;
int l[N], r[N];
set<int> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int a;
  cin >> a;
  m[a] = ++id;
  s.insert(a);
  for (int i = 1; i < n; i++) {
    cin >> a;
    m[a] = ++id;
    int p;
    auto it = s.upper_bound(a);
    if (it != s.end() && l[m[*it]] == 0) {
      l[m[*it]] = a;
      p = *it;
    } else {
      --it;
      r[m[*it]] = a;
      p = *it;
    }
    s.insert(a);
    cout << p << " ";
  }
  cout << '\n';

  return 0;
}
