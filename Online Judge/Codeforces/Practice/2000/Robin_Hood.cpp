#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int INF = 2e9;

int n;
long long k;
long long a[N];

bool can(long long x, bool flag) {
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (flag) {
      cnt += max(0LL, a[i] - x);
    } else {
      cnt += max(0LL, x - a[i]);
    }
    if (cnt > k) return false;
  }
  return true;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long l = 0, r = INF, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid, 0)) {
      l = mid + 1;
      best = mid;
    } else {
      r = mid - 1;
    }
  }
  long long cnt = k;
  for (int i = 1; i <= n; i++) {
    cnt -= max(0LL, best - a[i]);
    a[i] = max(a[i], best);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == best && cnt > 0) {
      cnt--;
      a[i]++;
    }
  }
  l = 0, r = INF, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid, 1)) {
      r = mid - 1;
      best = mid;
    } else {
      l = mid + 1;
    }
  }
  cnt = k;
  for (int i = 1; i <= n; i++) {
    cnt -= max(0LL, a[i] - best);
    a[i] = min(a[i], best);
  }
  long long maks = -1, mins = INF;
  for (int i = 1; i <= n; i++) {
    if (a[i] == best && cnt > 0) {
      cnt--;
      a[i]--;
    }
    maks = max(a[i], maks);
    mins = min(a[i], mins);
  }
  cout << maks - mins << '\n';

  return 0;
}