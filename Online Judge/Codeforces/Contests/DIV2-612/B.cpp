#include <bits/stdc++.h>

using namespace std;

const int N = 1505;
const int M = N * N;

int n, k;
string a[N];
pair<int, string> p[M];
int lenp;

char conv(char x, char y) {
  if (x == y) return x;
  for (char e : {'S', 'E', 'T'}) {
    if (e != x && e != y) return e;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<pair<int, string>> v;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      string res;
      res.resize(k);
      for (int it = 0; it < k; it++) {
        res[it] = conv(a[i][it], a[j][it]);
      }
      p[++lenp] = {j + 1, res};
    }
  }
  sort(p + 1, p + 1 + lenp);
  map<string, int> mp;
  int i = n, j = lenp;
  long long ans = 0;
  while (i >= 1 && j >= 1) {
    mp[a[i]]++;
    while (j >= 1 && p[j].first == i) {
      ans += (1LL) * mp[p[j].second];
      j--;
    }
    i--;
  }
  cout << ans << '\n';

  return 0;
}
