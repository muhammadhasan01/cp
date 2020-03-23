#include <bits/stdc++.h>

using namespace std;

int tc;
int n, m;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    cout << (n % m == 0 ? "YES" : "NO") << '\n';
  } 

  return 0;
}