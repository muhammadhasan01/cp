#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int tc;
int n;
char a[N], b[N], c[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (a[i] == '1') {
        if (i > 1) {
          if (!flag) {
            b[i] = '1';
            c[i] = '0';
            flag = true;
          } else {
            b[i] = '0';
            c[i] = '1';
          }
        } else {
          b[i] = c[i] = '2';
        }
      } else if (a[i] == '2') {
        if (i > 1) {
          if (!flag) {
            b[i] = c[i] = '1';
          } else {
            b[i] = '0';
            c[i] = '2';
          }
        } else {
          b[i] = c[i] = '1';
        }
      } else if (a[i] == '0') {
        if (i > 1) {
          b[i] = c[i] = '0';
        } else {
          b[i] = '2';
          c[i] = '1';
          flag = true;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << b[i];
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
      cout << c[i];
    }
    cout << '\n';
  }

  return 0;
}