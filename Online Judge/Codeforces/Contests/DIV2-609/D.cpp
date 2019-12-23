#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n;
long long sum, black;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    sum += x;
    black += (x + (i & 1)) / 2;
  }
  cout << min(black, sum - black) << '\n';

  return 0;
}
