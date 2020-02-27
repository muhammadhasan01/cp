#include <bits/stdc++.h>

using namespace std;

int tc;
int a, b, c;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    vector<int> cnt(3);
    for (int i = 0; i < 3; i++) {
      cin >> cnt[i];
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
      if (cnt[i] > 0) {
        cnt[i]--;
        ans++;
      }
    }
    sort(cnt.begin(), cnt.end());
    if (cnt[1] >= 1 && cnt[2] >= 1) {
      cnt[2]--;
      cnt[1]--;
      ans++;
    }
    if (cnt[0] >= 1 && cnt[2] >= 1) {
      cnt[2]--;
      cnt[0]--;
      ans++;
    }
    if (cnt[0] >= 1 && cnt[1] >= 1) {
      cnt[1]--;
      cnt[0]--;
      ans++;
    } 
    sort(cnt.begin(), cnt.end());
    if (cnt[0] >= 1) {
      ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}