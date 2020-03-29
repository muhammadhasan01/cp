#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d;
const int N = 1e6;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> c >> d;
  long long x = b, y = d;
  for (int i = 0; i < N; i++) {
    if (x < y) x += a;
    else if (y < x) y += c;
    else if (x == y) break;
  }
  cout << (x < N ? x : -1) << '\n';

  return 0;
}