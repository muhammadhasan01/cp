#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n;
int a[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++) {
      cout << a[i] << (i == n ? "\n" : " ");
    }
  }

  return 0;
}