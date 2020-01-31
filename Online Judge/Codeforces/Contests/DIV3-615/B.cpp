#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

struct st {
  int x, y;
};

int tc;
int n;
st a[N];
char ans[10 * N];

bool cmpr(st a, st b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n, cmpr);
    int cx = 0, cy = 0;
    int len = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      while (cx < a[i].x) {
        cx++;
        ans[++len] = 'R';
      }
      while (cy < a[i].y) {
        cy++;
        ans[++len] = 'U';
      }
      if (cx != a[i].x || cy != a[i].y) {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 1; i <= len; i++) {
        cout << ans[i];
      }
      cout << '\n';
    }
  }

  return 0;
}
