#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n;
bitset<N + 5> vis;
int ans[N + 5], lans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    vis[x] = 1;
  }
  vector<int> ans;
  int oc = 0;
  for (int i = 1; i <= N / 2; i++) {
    if (vis[i] == 1 && vis[N - i + 1] == 1) {
      oc++;
    } else if (vis[i] == 1) {
      ans[++lans] = N - i + 1;
    } else if (vis[N - i + 1] == 1) {
      ans[++lans] = i;
    }
  }
  for (int i = 1; i <= N / 2; i++) {
    if (vis[i] == 1 || vis[N - i + 1] == 1) continue;
    if (oc-- == 0) break;
    ans[++lans] = i;
    ans[++lans] = N - i + 1;
  }
  cout << lans << '\n';
  for (int i = 1; i <= lans; i++) {
    cout << ans[i] << (i == lans ? '\n' : ' ');
  }

  return 0;
}
