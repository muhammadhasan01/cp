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
    long long cnt = 0;
    long long chk = 0;
    while (b) {
      if (b % 10 == 9) chk++;
      b /= 10;
      cnt++;
    }
    if (cnt != chk) cnt--;
    cout << a * cnt << '\n';
  }

  return 0;
}
