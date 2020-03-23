#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e6;

int n, s, ll;
int a[N];
int dp[N];
multiset<int> st;
multiset<int> t;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s >> ll;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = INF;
  }
  for (int i = 1; i < ll; i++) {
    st.insert(a[i]);
  }
  int at = 1;
  for (int i = ll; i <= n; i++) {
    st.insert(a[i]);
    t.insert(dp[i - ll]);
    while (at <= i - ll + 1) {
      auto it = st.end();
      it--;
      int mks = *it;
      int min = *st.begin();
      if (mks - min <= s) break;
      it = st.lower_bound(a[at]);
      auto it2 = t.lower_bound(dp[at - ll]);
      t.erase(it2);
      st.erase(it);
      at++; 
    }
    if (at > i - ll + 1) {
      dp[i] = INF;
    } else {
      dp[i] = 1 + *t.begin();
    }
  }
  if (dp[n] == INF) dp[n] = -1;
  cout << dp[n];

  return 0;
}