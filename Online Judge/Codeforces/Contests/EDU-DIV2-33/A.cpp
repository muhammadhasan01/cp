#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int g = 3;
  for (int i = 1; i <= n; i++) {
    if (a[i] == g) {
      flag = false;
      break;
    }
    int trn = 0;
    for (int j = 1; j <= 3; j++) {
      if (j == a[i] || j == g) continue;
      trn = j;
    }
    g = trn;
  }
  cout << (flag ? "YES" : "NO") << '\n';

  return 0;
}
