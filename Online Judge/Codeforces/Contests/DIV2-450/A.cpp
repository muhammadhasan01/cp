#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
pair<int, int> p[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int c = 0, d = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
    if (p[i].first > 0) c++;
    else d++;
  }
  cout << (c >= 2 && d >= 2 ? "NO" : "YES") << '\n';

  return 0;
}
