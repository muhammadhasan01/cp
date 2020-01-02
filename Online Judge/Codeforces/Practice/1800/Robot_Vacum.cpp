#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<long long, long long>, string> plls;

const int N = 1e5 + 5;
int n;
plls p[N];
long long ans;

bool cmpr(plls a, plls b) {
  return (a.first.first * b.first.second > a.first.second * b.first.first);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int toth = 0;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    int h = 0, s = 0;
    for (auto e : str) {
      if (e == 'h') h++;
      else s++;
    }
    p[i].first = {s, h};
    p[i].second = str;
    toth += h;
  }
  sort(p + 1, p + 1 + n, cmpr);
  for (int i = 1; i <= n; i++) {
    for (auto e : p[i].second) {
      if (e == 's') ans += (1LL) * toth;
      else toth--;
    }
  }
  cout << ans << '\n';

  return 0;
}
