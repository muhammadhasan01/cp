#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

struct st {
  int sa, ea, sb, eb;
};

int n;
st a[N];
set<int> s;
map<int, int> mp;
int tot;
int t[4 * N], lazy[4 * N];

bool cmpr1(st x, st y) {
  if (x.sa == y.sa) return x.ea < y.ea;
  return x.sa < y.sa;
}

bool cmpr2(st x, st y) {
  if (x.sb == y.sb) return x.eb < y.eb;
  return x.sb < y.sb;
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = 0, lazy[v] = 0;
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
  }
}

void propagate(int v, int s, int e, int val) {
  if (val == 0) return;
  t[v] += val;
  if (s != e) {
    t[v << 1] += val;
    t[v << 1 | 1] += val;
  }
  lazy[v] = 0;
}

void update(int v, int s, int e, int l, int r, int val) {
  propagate(v, s, e, lazy[v]);
  if (e < l || s > r) return;
  if (l <= s && e <= r) {
    propagate(v, s, e, val);
    return;
  }
  int mid = (s + e) >> 1;
  update(v << 1, s, mid, l, r, val);
  update(v << 1 | 1, mid + 1, e, l, r, val);
  t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return 0;
  propagate(v, s, e, lazy[v]);
  if (l <= s & e <= r) return t[v];
  int mid = (s + e) >> 1;
  return max(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].sa >> a[i].ea >> a[i].sb >> a[i].eb;
    s.insert(a[i].sa);
    s.insert(a[i].ea);
    s.insert(a[i].sb);
    s.insert(a[i].eb);
  }
  for (auto e : s) {
    mp[e] = ++tot;
  }
  sort(a + 1, a + 1 + n, cmpr1);
  vector<pair<int, int>> qr;
  for (int i = 1; i < n; i++) {
    int l = i + 1, r = n, pos = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].sa > a[i].ea) {
        r = mid - 1;
        pos = mid;
      } else {
        l = mid + 1;
      }
    }
    if (pos == -1) continue;
    qr.push_back({pos, i});
  }
  build(1, 1, tot);
  sort(qr.begin(), qr.end(), greater<pair<int, int>>());
  int len = qr.size();
  int i = n, j = 0;
  while (i >= 1 && j < len) {
    update(1, 1, tot, mp[a[i].sb], mp[a[i].eb], 1);
    while (j < len && qr[j].first == i) {
      int id = qr[j].second;
      int res = get(1, 1, tot, mp[a[id].sb], mp[a[id].eb]);
      if (res != 0) {
        puts("NO");
        return 0;
      }
      j++;
    }
    i--;
  }
  sort(a + 1, a + 1 + n, cmpr2);
  qr.clear();
  build(1, 1, tot);
  for (int i = 1; i < n; i++) {
    int l = i + 1, r = n, pos = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].sb > a[i].eb) {
        r = mid - 1;
        pos = mid;
      } else {
        l = mid + 1;
      }
    }
    if (pos == -1) continue;
    qr.push_back({pos, i});
  }
  sort(qr.begin(), qr.end(), greater<pair<int, int>>());
  len = qr.size();
  i = n, j = 0;
  while (i >= 1 && j < len) {
    update(1, 1, tot, mp[a[i].sa], mp[a[i].ea], 1);
    while (j < len && qr[j].first == i) {
      int id = qr[j].second;
      int res = get(1, 1, tot, mp[a[id].sa], mp[a[id].ea]);
      if (res != 0) {
        puts("NO");
        return 0;
      }
      j++;
    }
    i--;
  }
  puts("YES");

  return 0;
}
