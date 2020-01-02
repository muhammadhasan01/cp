#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int vis[N];
int mp[N];
pair<int, int> ans[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    vis[a[i]]++;
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      pq.push(i);
      mp[i] = i;
    }
  }
  for (int j = n - 1; j >= 1; j--) {
    int cur = pq.top();
    ans[j] = {a[j], mp[cur]};
    vis[a[j]]--;
    if (a[j] > cur && vis[a[j]] == 0) {
      pq.pop();
      mp[a[j]] = a[j];
      pq.push(a[j]);
    } else if (vis[a[j]] > 0) {
      pq.pop();
    } else if (a[j] < cur && vis[a[j]] == 0) {
      mp[cur] = a[j];
    }
  }
  set<pair<int, int>> st;
  for (int i = 1; i < n; i++) {
    if (ans[i].first > ans[i].second) swap(ans[i].first, ans[i].second);
    if (ans[i].first == ans[i].second) {
      cout << -1 << '\n';
      return 0;
    }
    st.insert(ans[i]);
  }
  if ((int) st.size() != n - 1) {
    cout << -1 << '\n';
    return 0;
  }
  cout << a[1] << '\n';
  for (int i = 1; i < n; i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }

  return 0;
}
