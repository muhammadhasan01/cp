#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
long long a[N];
long double ans[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  stack<pair<long long, long long>> st;
  for (int i = 1; i <= n; i++) {
    long long val;
    cin >> val;
    long long sum = val;
    long long cnt = 1;
    while (!st.empty() && ((long double) sum) / cnt <= ((long double) st.top().first) / st.top().second) {
      sum += st.top().first;
      cnt += st.top().second;
      st.pop();
    }
    st.push({sum, cnt});
  }
  int cur_idx = n;
  while (!st.empty()) {
    auto cur = st.top();
    st.pop();
    long double res = ((long double) cur.first) / cur.second;
    for (int i = 0; i < cur.second; i++) {
      ans[cur_idx--] = res;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(12) << ans[i] << '\n';
  }

  return 0;
}