#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int b[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  a[1] = b[1];
  int maks = a[1];
  for (int i = 2; i <= n; i++) {
    a[i] = b[i] + maks;
    maks = max(a[i], maks);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}