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
    if (abs(n - k) % 2 == 0) {
      cout << (n >= k * k ? "YES" : "NO") << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}