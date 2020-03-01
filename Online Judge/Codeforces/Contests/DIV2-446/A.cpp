#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long b[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += (1LL) * x;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + 1 + n, greater<long long>());
  cout << (sum <= b[1] + b[2] ? "YES" : "NO") << '\n';

  return 0;
}