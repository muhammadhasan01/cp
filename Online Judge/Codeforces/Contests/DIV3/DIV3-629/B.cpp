#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
long long n, k;
long long pre[N];
char ans[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) ans[i] = 'a';
    pre[1] = n - 1;
    for (int i = 2; i <= n; i++) {
      pre[i] = (pre[i - 1] + n - i);
    }
    long long res = n * (n - 1) / 2 - k + 1;
    int l = 1, r = n, at = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (pre[mid] >= res) {
        r = mid - 1;
        at = mid;
      } else {
        l = mid + 1;
      }
    }
    long long dif = pre[at] - res;
    ans[at] = 'b';
    ans[n - dif] = 'b';
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }

  return 0;
}