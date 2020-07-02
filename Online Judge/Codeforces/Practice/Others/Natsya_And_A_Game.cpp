#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18 + 500;

int n;
int pre[N];
vector<pair<long long, int>> v;
long long k;
long long ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  v.push_back({0, 0});
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    pre[i] = pre[i - 1];
    if (x == 1) {
      pre[i]++;
    } else {
      v.push_back({x, i});
    }
  }
  pre[n + 1] = pre[n];
  if (k == 1) ans += pre[n];
  v.push_back({0, n + 1});
  int len = v.size() - 2;
  for (int i = 1; i <= len; i++) {
    long long prod = 1;
    long long sum = 0;
    for (int j = i; j <= i + 60; j++) {
      if (j > len) break;
      if (prod >= INF / v[j].first) break;
      prod *= v[j].first;
      sum += v[j].first;
      long long o1 = pre[v[j + 1].second] - pre[v[j].second];
      long long o2 = pre[v[i].second] - pre[v[i - 1].second];
      long long o3 = pre[v[j].second] - pre[v[i].second];
      if (prod % k != 0) continue;
      long long resprod = prod / k;
      long long cursum = sum + o3;
      if (cursum == resprod) ans++;
      else if (cursum < resprod) {
        if (o1 < o2) swap(o1, o2);
        long long dif = resprod - cursum;
        if (dif <= o1 + o2) {
          long long k = max(0LL, dif - o1);
          ans += min(dif + 1, max(0LL, o2 - k + 1));
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
