#include <bits/stdc++.h>

using namespace std;

int n;
multiset<long long> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
  }
  if (n % 2 == 0) s.insert(0);
  long long ans = 0;
  while ((int) s.size() > 1) {
    long long sum = *s.begin() + *(++s.begin()) + *(++(++s.begin()));
    for (int i = 0; i < 3; i++) s.erase(s.begin());
    s.insert(sum);
    ans += sum;
  }
  cout << ans << '\n';

  return 0;
}
