#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n;
int b[N];
int a[2 * N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    set<int> st;
    for (int i = 1; i <= 2 * n; i++) st.insert(i);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      st.erase(b[i]);
      a[2 * i - 1] = b[i];
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      auto it = st.lower_bound(b[i]);
      if (it == st.end()) {
        flag = true;
        break;
      }
      a[2 * i] = *it;
      st.erase(it);
    }
    if (flag) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 1; i <= 2 * n; i++) {
      cout << a[i] << (i == 2 * n ? '\n' : ' ');
    }
  }

  return 0;
}