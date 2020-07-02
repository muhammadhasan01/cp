#include <bits/stdc++.h>

using namespace std;

const int N = 35;
const int K = 105;
const long long INF = 1e16;

int tc;
int n;
long long k;
long long a[N];
vector<long long> v[K];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (long long i = 2; i < K; i++) {
    long long cur = 1;
    while (cur <= INF) {
      v[i].push_back(cur);
      cur = (cur * i);
    }
  }
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    vector<int> cnt(K);
    for (int i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      while (x > 0) {
        int pos = upper_bound(v[k].begin(), v[k].end(), x) - v[k].begin() - 1;
        x -= v[k][pos];
        cnt[pos]++;
      }
    }
    bool flag = true;
    for (int i = 0; i < K; i++) {
      if (cnt[i] > 1) {
        flag = false;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}