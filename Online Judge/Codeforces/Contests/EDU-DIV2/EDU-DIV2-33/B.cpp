#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int n, ans = 1;
deque<int> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k = 0;
  int cur = 1;
  while (cur <= N) {
    v.push_front(cur);
    k++;
    cur = ((1 << k) - 1) * (1 << (k - 1));
  }

  cin >> n;
  for (auto e : v) {
    if (n % e == 0) {
      cout << e << '\n';
      return 0;
    }
  }

  return 0;
}
