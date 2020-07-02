#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
int l[N];
int cnt[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    cnt[max(0, i - l[i])]++;
    cnt[i]--;
  }
  int ans = n;
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
    if (cnt[i] > 0) ans--;
  }
  cout << ans << '\n';

  return 0;
}