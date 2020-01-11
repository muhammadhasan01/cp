#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n;
int a[N], dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> st;
  st.push(1);
  int ans = 0;
  dp[1] = INF;
  for (int i = 2; i <= n; i++) {
    dp[i] = 1;
    while (!st.empty() && a[st.top()] < a[i]) {
      dp[i] = max(dp[i], dp[st.top()] + 1);
      st.pop();
    }
    if (dp[i] > ans && dp[i] < INF) ans = dp[i];
    st.push(i);
  }
  cout << ans << '\n';

  return 0;
}
