#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
short int a[N];
int cur;
vector<pair<int, int>> ans;
int pre[N][3];

int binser(int pos, int turn, int t) {
  int ret = n + 1;
  int l = pos, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (pre[mid][turn] - pre[pos - 1][turn] >= t) {
      r = mid - 1;
      ret = mid;
    } else {
      l = mid + 1;
    }
  }
  if (pre[ret][turn] - pre[pos - 1][turn] != t) return n + 1;
  return ret;
}

void check(int t) {
  int pos = 1;
  int ocur = 3 - cur;
  int s1 = 0, s2 = 0;
  while (pos <= n) {
    int id_1 = binser(pos, cur, t);
    int id_2 = binser(pos, ocur, t);
    pos = min(id_1, id_2) + 1;
    if (id_1 < id_2) {
      s1++;
    } else if (id_2 < id_1) {
      s2++;
    } else {
      return;
    }
  }
  if (s1 <= s2) return;
  ans.push_back({s1, t});
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  vector<int> cnt(3);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= 2; j++) pre[i][j] = pre[i - 1][j];
    pre[i][a[i]]++;
  }
  cur = a[n];
  int total = pre[n][cur];
  for (int i = 1; i <= total; i++) check(i);
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (auto e : ans) {
    cout << e.first << " " << e.second << '\n';
  }

  return 0;
}