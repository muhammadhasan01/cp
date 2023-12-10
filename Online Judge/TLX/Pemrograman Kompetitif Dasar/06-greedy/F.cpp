#include <bits/stdc++.h>
#define int long long

using namespace std;

int binser(int money, int price, int len, int cheapest) {
  int l = 0, r = money / price;
  int ret = 0;

  while (l <= r) {
    int mid = (l + r) / 2LL;
    int rem = money - (price * mid);
    if (rem / cheapest + mid >= len) {
      l = mid + 1LL;
      ret = mid;
    } else {
      r = mid - 1LL;
    }
  }

  return ret;
}

void printAns(deque<int>& ans) {
  while (!ans.empty()) {
    cout << ans.front();
    ans.pop_front();
  }

  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n + 1), tmp(n + 1);
  int mini = LLONG_MAX;

  for (int i = 0; i <= n; i++) {
    cin >> v[i].first;
    v[i].second = i;
    mini = min(mini, v[i].first);
  }

  int m;
  cin >> m;

  int len = m / mini;

  tmp = v;
  sort(tmp.begin(), tmp.end());
  if (tmp[0].second == 0) {
    if (n && m >= tmp[1].first) {
      len = (m - tmp[1].first) / mini + 1LL;
    } else {
      len = (m >= tmp[0].first);
    }
  }

  int ans = len;
  deque<int> ans1, ans2;
  bool zero = false;

  for (int i = n; i >= 0; i--) {
    int buy = binser(m, v[i].first, len, mini);
    m -= v[i].first * buy;
    len -= buy;

    while (ans1.size() < 50 && buy) {
      ans1.push_back(i);
      ans2.push_back(i);
      buy--;
      if ((ans1.size() == 1) && i == 0) {
        ans = 1;
        zero = true;
        break;
      }
    }

    if (zero) break;

    if (buy) {
      if (buy >= 50) {
        ans2.clear();
        for (int j = 1; j <= 50; j++) ans2.push_back(i);
      } else {
        for (int j = 1; j <= buy; j++) {
          ans2.pop_front();
          ans2.push_back(i);
        }
      }
    }
  }

  if (!ans) {
    cout << 0 << '\n';
    return 0;
  }

  cout << ans << '\n';
  printAns(ans1);
  printAns(ans2);

  return 0;
}