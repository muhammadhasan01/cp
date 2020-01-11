#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  cout << max(10LL, 5 * ((n + k - 1) / k)) << '\n';

  return 0;
}
