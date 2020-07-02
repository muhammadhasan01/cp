#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k;
string s;
short int ans[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  cin >> s;
  bool flag = false;
  for (int i = 0; i < k; i++) {
    ans[i] = (int) (s[i] - '0');
  }
  for (int i = k; i < n; i++) {
    if (s[i] > s[i % k]) {
      flag = true;
      break;
    } else if (s[i] < s[i % k]) {
      break;
    }
  }
  if (flag) {
    for (int i = k - 1; i >= 0; i--) {
      if (ans[i] == 9) {
        ans[i] = 0;
        continue;
      }
      ans[i]++;
      break;
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i % k];
  }
  cout << '\n';

  return 0;
}
