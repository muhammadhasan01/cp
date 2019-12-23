#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;
int tc;
long long a, b;
vector<long long> v1, v2;
vector<int> k1, k2;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long i = 1;
  while (i * (i + 1) / 2 <= INF) {
    long long cur = i * (i + 1) / 2;
    if (cur & 1) {
      v1.push_back(cur);
      k1.push_back(i);
    } else {
      v2.push_back(cur);
      k2.push_back(i);
    }
    i++;
  }

  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    if (a < b) swap(a, b);
    long long dif = a - b;
    if (dif == 0) {
      cout << 0 << '\n';
      continue;
    }
    if (dif & 1) {
      int pos = lower_bound(v1.begin(), v1.end(), dif) - v1.begin();
      cout << k1[pos] << '\n';
    } else {
      int pos = lower_bound(v2.begin(), v2.end(), dif) - v2.begin();
      cout << k2[pos] << '\n';
    }
  }

  return 0;
}
