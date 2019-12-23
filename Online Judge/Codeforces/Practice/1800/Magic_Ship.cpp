#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;
long long x_1, y_1, x_2, y_2;
int n;
string s;
pair<long long, long long> pre[N];

bool can(long long k) {
  long long x = x_1 + pre[n].first * (k / n) + pre[k % n].first;
  long long y = y_1 + pre[n].second * (k / n) + pre[k % n].second;
  long long dif = abs(x_2 - x) + abs(y_2 - y);
  return (k >= dif);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> x_1 >> y_1 >> x_2 >> y_2 >> n >> s;
  for (int i = 1; i <= n; i++) {
    char x = s[i - 1];
    pre[i] = pre[i - 1];
    if (x == 'U') {
      pre[i].second++;
    } else if (x == 'D') {
      pre[i].second--;
    } else if (x == 'L') {
      pre[i].first--;
    } else if (x == 'R') {
      pre[i].first++;
    }
  }
  long long l = 1, r = INF, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
