#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 10) + 5;
int n, k, x;
int cnt[N], tmp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    int q;
    cin >> q;
    cnt[q]++;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < N; j++) tmp[j] = cnt[j];
    int par = 0;
    for (int j = 0; j < N; j++) {
      if (cnt[j] > 0) {
        int cur = j ^ x;
        int change = (cnt[j] / 2);
        if (par == 0) change += (cnt[j] & 1);
        tmp[j] -= change;
        tmp[cur] += change;
        par ^= (cnt[j] & 1);
      }
    }
    for (int j = 0; j < N; j++) cnt[j] = tmp[j];
  }
  int maks = -1, mins = 1e9;
  for (int i = 0; i < N; i++) {
    if (cnt[i] > 0) {
      maks = max(maks, i);
      mins = min(mins, i);
    }
  }
  cout << maks << " " << mins << '\n';

  return 0;
}
