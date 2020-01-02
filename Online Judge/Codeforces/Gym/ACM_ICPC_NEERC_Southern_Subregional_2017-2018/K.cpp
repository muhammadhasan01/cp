#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;
int n;
int le[N], ri[N];
int pos[N];
int ans[N];
pair<int, int> t[4 * N];
bool vis[N];

void dismiss() {
  puts("-1");
  exit(0);
}

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first ? a : b);
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = {pos[s], s};
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
}

void update(int v, int s, int e, int pos, int val) {
  if (s == e && s == pos) {
    t[v] = {val, s};
  } else {
    int mid = (s + e) >> 1;
    if (pos <= mid) {
      update(v << 1, s, mid, pos, val);
    } else {
      update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
}

pair<int, int> get(int v, int s, int e, int l, int r) {
  if (s > r || e < l) return {INF, 0};
  if (l <= s && e <= r) return t[v];
  int mid = (s + e) >> 1;
  return merge(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

bool check(int i, int x) {
  return (le[i] <= x && x <= ri[i]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> le[i] >> ri[i];
    ri[i] += le[i];
    pos[i] = INF;
  }
  if (n == 1) {
    cout << ri[1] - le[1] << '\n';
    cout << ri[1] << '\n';
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (ri[i] < le[i + 1] - 1) dismiss();
    if (ri[i + 1] < le[i] - 1) dismiss();
    if (abs(ri[i] - ri[i + 1]) <= 1) {
      pos[i] = min(pos[i], ri[i]);
      pos[i + 1] = min(pos[i + 1], ri[i + 1]);
    } else if (ri[i] < ri[i + 1] - 1) {
      pos[i] = min(pos[i], ri[i]);
      pos[i + 1] = min(pos[i + 1], ri[i] + 1);
    } else if (ri[i] - 1 > ri[i + 1]) {
      pos[i] = min(pos[i], ri[i + 1] + 1);
      pos[i + 1] = min(pos[i + 1], ri[i + 1]);
    }
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    pair<int, int> k = get(1, 1, n, 1, n);
    int val = k.first;
    int place = k.second;
    vis[place] = 1;
    ans[place] = val;
    if (place - 1 >= 1 && vis[place - 1] == 0) {
      bool flag = true;
      for (int j = 1; j >= -1; j--) {
        if (check(place - 1, val + j)) {
          vis[place - 1] = 1;
          update(1, 1, n, place - 1, val + j);
          flag = false;
          break;
        }
      }
      if (flag) dismiss();
    }
    if (place + 1 <= n && vis[place + 1] == 0) {
      bool flag = true;
      for (int j = 1; j >= -1; j--) {
        if (check(place + 1, val + j)) {
          vis[place + 1] = 1;
          update(1, 1, n, place + 1, val + j);
          flag = false;
          break;
        }
      }
      if (flag) dismiss();
    }
    update(1, 1, n, place, INF);
  }
  long long res = 0;
  for (int i = 1; i <= n; i++)
    res += (1LL) * (ans[i] - le[i]);
  cout << res << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
