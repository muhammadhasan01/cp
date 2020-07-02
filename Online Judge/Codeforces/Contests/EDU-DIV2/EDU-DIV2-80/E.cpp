#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;


int n, m;
int a[N];
int mini[N], maxi[N];
bool vis[N];
vector<int> g[N];
int bit[N];
int block, cnt[N], res;

struct st {
  int l, r, val;
};

vector<st> qr;

bool cmpr(st a, st b) {
  if (a.l / block == b.l / block)
    return a.r / block < b.r / block;
  return a.l / block < b.l / block;
}

void add(int x, int val) {
  for ( ; x <= n; x += x & -x) bit[x] += val;
}

int get(int x) {
  int ret = 0;
  for ( ; x > 0; x -= x & -x) ret += bit[x];
  return ret;
}

void addz(int pos) {
  if (++cnt[a[pos]] == 1) res++;
}

void deletez(int pos) {
  if (--cnt[a[pos]] == 0) res--;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    mini[i] = maxi[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    g[a[i]].push_back(i);
    if (vis[a[i]]) continue;
    add(a[i], 1);
    maxi[a[i]] = a[i] + get(n) - get(a[i]);
    vis[a[i]] = 1;
    mini[a[i]] = 1;
  }
  block = sqrt(n + 1);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      g[i].push_back(m + 1);
      int len = g[i].size();
      for (int j = 0; j < len - 1; j++) {
        if (g[i][j] + 1 == g[i][j + 1]) continue;
        qr.push_back({g[i][j] + 1, g[i][j + 1] - 1, i});
      }
    } else {
      maxi[i] = i + get(n) - get(i);
    }
  }
  sort(qr.begin(), qr.end(), cmpr);
  int lenz = qr.size();
  int curl = 0, curr = 0;
  for (int i = 0; i < lenz; i++) {
    while (curl < qr[i].l) {
      deletez(curl++);
    }
    while (curl > qr[i].l) {
      addz(--curl);
    }
    while (curr <= qr[i].r) {
      addz(curr++);
    }
    while (curr > qr[i].r + 1) {
      deletez(--curr);
    }
    maxi[qr[i].val] = max(maxi[qr[i].val], res + 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << mini[i] << " " << maxi[i] << '\n';
  }

  return 0;
}
