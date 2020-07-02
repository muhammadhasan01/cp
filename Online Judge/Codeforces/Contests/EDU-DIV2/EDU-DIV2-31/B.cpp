#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long x;
long long a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum += (1LL) * (n - 1);
  puts(sum == x ? "YES" : "NO");

  return 0;
}
