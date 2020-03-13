#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

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
    vector<int> cnt(2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i] % 2]++;
    }
    cout << (cnt[0] > 0 && cnt[1] > 0 ? "NO" : "YES") << '\n';
  }

  return 0;
}