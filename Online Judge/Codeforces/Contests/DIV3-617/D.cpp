#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a, b, k;
int h;

int ceil(int n, int k) {
  return (n + k - 1) / k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> a >> b >> k;
  int ans = 0;
  vector<int> need;
  for (int i = 1; i <= n; i++) {
    int h;
    cin >> h;
    h %= (a + b);
    if (h == 0) h = a + b;
    if (h <= a) {
      ans++;
    } else if (h > a) {
      need.push_back(ceil(h - a, a));
    }
  }
  sort(need.begin(), need.end());
  for (auto e : need) {
    if (k >= e) {
      ans++;
      k -= e;
    }
  }
  cout << ans << '\n';

  return 0;
}
