#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    cout << ((a + b - 1) / b) * b - a << '\n';
  }

  return 0;
}