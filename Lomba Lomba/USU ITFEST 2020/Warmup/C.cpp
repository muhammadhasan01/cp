#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m;
int a[N];
int cnt[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    cnt[x] = 1;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] == 1) ans.push_back(a[i]);
  }
  int len = ans.size();
  for (int i = 0; i < len; i++) {
    cout << ans[i] << (i == len - 1 ? '\n' : ' ');
  }

  return 0;
}