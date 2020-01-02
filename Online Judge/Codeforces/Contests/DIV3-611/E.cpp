#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n;
int x[N], y[N];
set<int> mins_oc, maks_oc;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x + 1, x + 1 + n);
  vector<int> v;
  v.push_back(-1);
  int last = x[1];
  for (int i = 1; i <= n; i++) {
    y[i] = x[i];
    if (x[i] != last) {
      v.push_back(last);
      last = x[i];
    }
  }
  v.push_back(last);
  int len = v.size() - 1;
  for (int i = 1; i <= len; i++) {
    if (v[i - 1] < v[i] - 1) {
      v[i]++;
    } else if (v[i] - v[i - 1] == 1) {
      v[i]--;
    }
    mins_oc.insert(v[i]);
  }
  y[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (y[i - 1] < y[i] - 1) {
      y[i]--;
    } else if (y[i - 1] >= y[i]) {
      y[i]++;
    }
    maks_oc.insert(y[i]);
  }
  cout << mins_oc.size() << " " << maks_oc.size() << '\n';

  return 0;
}
