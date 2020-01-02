#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k;
int a[N], b[N];
vector<pair<int, char>> ans;

void dismiss() {
  puts("NO");
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }
  int i = 1, j = 1;
  int sum = 0;
  while (j <= k) {
    if (a[i] == b[j]) {
      i++, j++;
      continue;
    }
    int pos = i;
    while (i <= n && sum < b[j]) sum += a[i++];
    if (sum != b[j]) dismiss();
    int maks = -1;
    for (int it = pos; it <= i - 1; it++) maks = max(maks, a[it]);
    bool flag = true;
    for (int it = pos; it <= i - 1; it++) {
      if (a[it] == maks) {
        if (it + 1 <= i - 1 && a[it + 1] < maks) {
          flag = false;
          int cnt = it;
          while (cnt < i - 1) {
            ans.push_back({it - pos + j, 'R'});
            cnt++;
          }
          cnt = it;
          while (cnt > pos) {
            ans.push_back({cnt - pos + j, 'L'});
            cnt--;
          }
          break;
        } else if (it - 1 >= pos && a[it - 1] < maks) {
          flag = false;
          int cnt = it;
          while (cnt > pos) {
            ans.push_back({cnt - pos + j, 'L'});
            cnt--;
          }
          cnt = it;
          while (cnt < i - 1) {
            ans.push_back({j, 'R'});
            cnt++;
          }
          break;
        }
      }
    }
    if (flag) dismiss();
    sum = 0;
    j++;
  }

  if ((int) ans.size() != n - k) dismiss();

  cout << "YES" << '\n';
  for (auto e : ans) {
    cout << e.first << " " << e.second << '\n';
  }

  return 0;
}
