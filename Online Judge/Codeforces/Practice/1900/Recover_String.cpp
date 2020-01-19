#include <bits/stdc++.h>

using namespace std;

long long a[2][2];

void dismiss() {
  cout << "Impossible" << '\n';
  exit(0);
}

long long get(long long x) {
  if (x == 0) return 0;
  long long l = 0, r = 1e9, ret = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (mid * (mid - 1) / 2 <= x) {
      l = mid + 1;
      ret = mid;
    } else {
      r = mid - 1;
    }
  }
  if (ret * (ret - 1) / 2 != x) dismiss();
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
  if (a[0][0] + a[0][1] + a[1][0] + a[1][1] == 0) {
    cout << "0" << '\n';
    return 0;
  }
  long long c1 = get(a[0][0]);
  long long c2 = get(a[1][1]);
  if (a[0][0] + a[1][1] == 0) {
    if (a[1][0] + a[0][1] > 1) dismiss();
    if (a[1][0] == 1) {
      cout << "10" << '\n';
      return 0;
    } else if (a[0][1] == 1) {
      cout << "01" << '\n';
      return 0;
    }
  } else if (a[0][0] == 0) {
    if (a[1][0] || a[0][1]) c1 = 1;
  } else if (a[1][1] == 0) {
    if (a[1][0] || a[0][1]) c2 = 1;
  }
  if (c1 * c2 != a[1][0] + a[0][1]) dismiss();
  long long cur = c1 * c2;
  long long cnt = 0;
  deque<char> ans(c2, '1');
  while (cnt < c1) {
    cnt++;
    if (cur - c2 >= a[0][1]) {
      ans.push_back('0');
      cur -= c2;
    } else {
      ans.insert(ans.begin() + (cur - a[0][1]), '0');
      cur = a[0][1];
    }
    if (cur == a[0][1]) {
      while (cnt < c1) {
        ans.push_front('0');
        cnt++;
      }
    }
  }
  for (auto e : ans) cout << e;
  cout << '\n';

  return 0;
}
