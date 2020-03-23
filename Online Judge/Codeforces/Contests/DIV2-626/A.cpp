#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int a[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x & 1) {
        odd.push_back(i);
      } else {
        even.push_back(i);
      }
    }
    if ((int) even.size() > 0) {
      cout << 1 << '\n';
      cout << even[0] << '\n';
    } else if ((int) odd.size() > 1) {
      cout << 2 << '\n';
      cout << odd[0] << " " << odd[1] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}