#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m;
bool prime[N];
vector<int> primes;
map<pair<int, int>, int> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  prime[1] = 1;
  for (long long i = 2; i < N; i++) {
    if (prime[i] == 0) {
      primes.push_back(i);
      for (long long j = i * i; j < N; j += i)
        prime[j] = 1;
    }
  }

  cin >> n >> m;
  int val = *lower_bound(primes.begin(), primes.end(), n);
  cout << val << " " << val << '\n';
  for (int i = 1; i <= n - 2; i++) {
    cout << i << " " << i + 1 << " " << 1 << '\n';
    mp[{i, i + 1}] = 1;
  }
  cout << n - 1 << " " << n << " " << val - (n - 2) << '\n';
  m -= (n - 1);
  if (m == 0) return 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!mp[{i, j}]) {
        mp[{i, j}] = 1;
        cout << i << " " << j << " " << INF << '\n';
        if (--m == 0) return 0;
      }
    }
  }

  return 0;
}
