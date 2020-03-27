#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int q;
int n;
int t[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (t[i] != t[i + 1]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << 1 << '\n';
      for (int i = 1; i <= n; i++) {
        cout << 1 << ' ';
      }
      cout << '\n';
      continue;
    }
    if (n % 2 == 0) {
      cout << 2 << '\n';
      for (int i = 0; i < n; i++) {
        cout << (i % 2) + 1 << ' ';
      }
      cout << '\n';
      continue;
    }
    if (t[1] == t[n]) {
      cout << 2 << '\n';
      for (int i = 0; i < n - 1; i++) cout << (i % 2) + 1 << " ";
      cout << 1 << '\n';
      continue;
    } else {
      bool flag = false;
      for (int i = 2; i <= n; i++) {
        if (t[i - 1] == t[i]) {
          cout << 2 << '\n';
          for (int j = 0; j < i - 1; j++) cout << (j % 2) + 1 << " ";
          for (int j = i - 1; j < n; j++) cout << ((j + 1) % 2) + 1 << " ";
          cout << '\n';
          flag = true;
          break;
        }
      }
      if (flag) continue;
    }
    cout << 3 << '\n';
    for (int i = 0; i < n - 1; i++) cout << (i % 3) + 1 << " ";
    int last = ((n - 1) % 3) + 1;
    if (last == 1) last = 2;
    cout << last << '\n';
  }

  return 0;
}