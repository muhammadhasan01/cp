#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 205;

int n;
char a[N][N];
int pre[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n / 4; j++) {
      char x;
      cin >> x;
      int cur;
      if ('0' <= x && x <= '9') {
        cur = (x - '0');
      } else {
        cur = (x - 'A') + 10;
      }
      string temp = "";
      while (cur > 0) {
        if (cur & 1) temp = "1" + temp;
        else temp = "0" + temp;
        cur /= 2;
      }
      while ((int) temp.size() < 4) temp = "0" + temp;
      for (int k = 4 * j - 3, c = 0; c < 4; k++, c++) a[i][k] = temp[c];
    }
  }
  for (int i = 1; i <= n; i++) {
    int c = 0;
    for (int j = 1; j <= n; j++) {
      pre[i][j] = c + pre[i - 1][j];
      if (a[i][j] == '1')
        pre[i][j]++, c++;
    }
  }
  vector<int> div;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end(), greater<int>());
  for (auto e : div) {
    int cur = n / e;
    int need = e * e;
    bool flag = true;
    for (int i = e; i <= n; i += e) {
      for (int j = e; j <= n; j += e) {
        int res = pre[i][j] - pre[i - e][j] - pre[i][j - e] + pre[i - e][j - e];
        if (0 < res && res < need) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) {
      cout << e << '\n';
      return 0;
    }
  }

  return 0;
}
