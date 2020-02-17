#include <bits/stdc++.h>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k;
  cin >> k;
  if (k % 2 == 0) {
    cout << "NO" << '\n';
    return 0;
  } else if (k == 1) {
    cout << "YES" << '\n';
    cout << 2 << " " << 1 << '\n';
    cout << 1 << " " << 2 << '\n';
    return 0;
  }
  int n = k * k + k + 2;
  int m = (n * k) / 2;
  cout << "YES" << '\n';
  cout << n << " " << m << '\n';
  for (int u = 1; u <= k + 1; u++) {
    for (int v = u + 1; v <= k + 1; v++) {
      if (u == 1 && v == 2) continue;
      cout << u << " " << v << '\n';
    }
  }
  cout << 1 << " " << k + 2 << '\n';
  cout << 2 << " " << k + 3 << '\n';
  int cur = k + 3;
  for (int it = 1; it <= (k - 1) / 2; it++) {
    for (int u = 1; u <= k + 1; u++) {
      for (int v = u + 1; v <= k + 1; v++) {
        if (u == 1 && v == 2) continue;
        cout << u + cur << " " << v + cur << '\n';
      }
    }
    cout << (k + 2) << " " << 1 + cur << '\n';
    cout << (k + 2) << " " << 2 + cur << '\n';
    cur += (k + 1);
    for (int u = 1; u <= k + 1; u++) {
      for (int v = u + 1; v <= k + 1; v++) {
        if (u == 1 && v == 2) continue;
        cout << u + cur << " " << v + cur << '\n';
      }
    }
    cout << (k + 3) << " " << 1 + cur << '\n';
    cout << (k + 3) << " " << 2 + cur << '\n'; 
    cur += (k + 1);
  }


  return 0;
}