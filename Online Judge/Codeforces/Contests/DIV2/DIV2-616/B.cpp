#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int tc;
int n;
int a[N];
bool pre[N], suf[N];

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
    pre[0] = true;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1];
      int cur = i - 1;
      if (a[i] < cur) {
        pre[i] = false;
      }
    }
    suf[n + 1] = true;
    for (int i = n; i >= 1; i--) {
      suf[i] = suf[i + 1];
      int cur = n - i;
      if (a[i] < cur) {
        suf[i] = false;
      }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      int cur = max(i - 1, n - i);
      if (pre[i - 1] && a[i] >= cur && suf[i + 1]) {
        flag = true;
        break;
      }
    }
    cout << (flag ? "Yes" : "No") << '\n';
  }

  return 0;
}
