#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n, q;
  cin >> n >> q;
  int t;
  long long x;
  long long sum = 0;
  long long pos_odd = 0, pos_even = 0;
  int turn = 1;
  for (int i = 1; i <= q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      sum += x;
      if (x & 1) turn = -turn;
    } else if (t == 2) {
      pos_odd += turn;
      pos_even -= turn;
      turn = -turn;
    }
  }
  vector<int> pos(n + 1);
  for (long long i = 1; i <= n; i++) {
    long long cur = ((i + sum + (i & 1 ? pos_odd : pos_even)) % n + n) % n;
    if (cur == 0) cur = n;
    pos[cur] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << pos[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
