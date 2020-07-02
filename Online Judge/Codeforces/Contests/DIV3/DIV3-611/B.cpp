#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    long long x = n / k;
    long long rem = n - x * k;
    cout << x * k + min(rem, k / 2) << '\n';
  }

  return 0;
}
