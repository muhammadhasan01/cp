#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int INF = 1e8;

int n, m;
int pre[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    pre[i] = (i - 1) / 2 + pre[i - 1];
  }
  int maks = pre[n];
  if (maks < m) {
    cout << -1 << '\n';
    return 0;
  } else if (maks == m) {
    for (int i = 1; i <= n; i++) {
      cout << i << (i == n ? '\n' : ' ');
    }
    return 0;
  }
  int l = 0, r = n, best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (pre[mid] >= m) {
      r = mid - 1;
      best = mid;
    } else {
      l = mid + 1;
    }
  }
  if (pre[best] == m) {
    for (int i = 1; i <= best; i++) cout << i << " ";
    for (int i = best + 1; i <= n; i++) cout << INF + 5000 * i << " ";
    cout << '\n';
    return 0;
  }
  best--;
  int dif = m - pre[best];
  l = best + 1, r = INF;
  int at = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if ((best - (mid - best) + 1) / 2 >= dif) {
      l = mid + 1;
      at = mid;
    } else {
      r = mid - 1;
    }
  }
  for (int i = 1; i <= best; i++) cout << i << " ";
  cout << at << " ";
  for (int i = best + 2; i <= n; i++) cout << INF + 5000 * i << " ";
  cout << '\n';

  return 0;
}