#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
int n;
int prime[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 2; i < N; i++) {
    if (prime[i] == 0) {
      for (int j = i; j < N; j += i)
        prime[j]++;
    }
  }
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (prime[i] == 2) ans++;
  cout << ans << '\n';

  return 0;
}
