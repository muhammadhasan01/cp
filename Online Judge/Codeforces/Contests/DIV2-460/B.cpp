#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int len = 0;
vector<long long> v;

bool check(long long x) {
  int ret = 0;
  while (x > 0) {
    ret += (x % 10);
    if (ret > 10) return false;
    x /= 10;
  }
  return (ret == 10);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long cur = 19;
  while (len < N) {
    while (!check(cur)) cur += 9;
    v.push_back(cur);
    cur += 9;
    len++;
  }
  int k;
  cin >> k;
  cout << v[k - 1] << '\n';

  return 0;
}
