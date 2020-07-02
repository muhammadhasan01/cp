#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n;
int f[N];
bool vis[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    vis[f[i]] = 1;
  }
  deque<int> av;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) av.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == 0 && vis[i] == 0) {
      if (av.back() != i) {
        f[i] = av.back();
        av.pop_back();
      } else {
        f[i] = av.front();
        av.pop_front();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == 0) {
      if (av.back() != i) {
        f[i] = av.back();
        av.pop_back();
      } else {
        f[i] = av.front();
        av.pop_front();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << f[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
