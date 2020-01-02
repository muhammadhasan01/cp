#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n;
int fib[N];
bool fibb[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  fib[0] = fib[1] = 1;
  fibb[1] = 1;
  for (int i = 2; i <= 100; i++) {
    fib[i] = fib[i - 2] + fib[i - 1];
    if (fib[i] > N) break;
    fibb[fib[i]] = 1;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << (fibb[i] ? 'O' : 'o');
  }
  cout << '\n';

  return 0;
}
