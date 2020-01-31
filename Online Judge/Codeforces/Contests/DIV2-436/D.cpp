#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], cnt[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  vector<int> need;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      ++ans;
      need.push_back(i);
    }
  }
  vector<bool> vis(n + 1);
  int j = 0;
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] > 1) {
      if (need[j] < a[i] || vis[a[i]] == 1) {
        cnt[a[i]]--;
        a[i] = need[j++];
      } else {
        vis[a[i]] = 1;
      }
    }
    cout << a[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
