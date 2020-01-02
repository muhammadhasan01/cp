#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
map<int, int> curmp, mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  int cnt = 0;
  while (n) {
    if (n % 2 == 1) ++curmp[cnt], ++mp[cnt];
    n /= 2;
    cnt++;
  }
  int cur = curmp.size();
  while (cur < k) {
    int x = (--curmp.end()) -> first;
    curmp[x - 1] += 2;
    if (--curmp[x] == 0) curmp.erase(x);
    ++cur;
  }
  int mx = (--curmp.end()) -> first;
  cur = mp.size();
  while (cur < k) {
    int x = (--mp.end()) -> first;
    if (x == mx) break;
    mp[x - 1] += 2;
    if (--mp[x] == 0) mp.erase(x);
    ++cur;
  }
  while (cur < k) {
    int x = mp.begin() -> first;
    mp[x - 1] += 2;
    if (--mp[x] == 0) mp.erase(x);
    ++cur;
  }
  if (cur != k) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
    deque<int> ans;
    for (auto e : mp) {
      for (int i = 1; i <= e.second; i++) {
        ans.push_front(e.first);
      }
    }
    for (auto e : ans) {
      cout << e << " ";
    }
    cout << '\n';
  }

  return 0;
}
