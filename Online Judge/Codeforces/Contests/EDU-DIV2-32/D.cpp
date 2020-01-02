#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  if (k == 1) {
    cout << 1LL << '\n';
  } else if (k == 2) {
    cout << 1LL + n * (n - 1LL) / 2LL << '\n';
  } else if (k == 3) {
    cout << 1LL + n * (n - 1LL) / 2LL + 2LL * n * (n - 1LL) * (n - 2LL) / 6LL << '\n';
  } else {
    cout << 1LL + n * (n - 1LL) / 2LL + 2LL * n * (n - 1LL) * (n - 2LL) / 6LL  + 9LL * n * (n - 1LL) * (n - 2LL) * (n - 3LL) / 24LL << '\n';
  }

  return 0;
}
