#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int q, x, y;
int cnt[N], rcnt[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> q >> x;
  int cur = 0;
  while (q--) {
    cin >> y;
    cnt[y % x]++;
    while (cnt[cur % x] > 0) {
      cnt[cur % x]--;
      cur++;
    }
    cout << cur << '\n';
  }

  return 0;
}
