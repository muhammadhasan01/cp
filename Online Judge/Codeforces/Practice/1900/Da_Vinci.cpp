#include <bits/stdc++.h>

using namespace std;

long long n, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  if (n >= 13) {
    ans = 8092 * (1LL << (n - 13));
  } else {
    ans = (1LL << n);
  }
  cout << ans << '\n';

  return 0;
}
