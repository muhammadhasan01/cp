#include <bits/stdc++.h>

using namespace std;

struct st {
  int l, r, idx;
};

const int N = 1e5 + 5;
const int M = 1e7 + 5;
int n, m, k;
int a[N], cnt[M];
int block;
st q[N];
long long res, ans[N];

bool cmpr(st a, st b) {
  if (a.l / block != b.l / block)
    return a.l / block < b.l / block;
  return a.r / block < b.r / block;
}

void del(int x) {
  cnt[a[x]]--;
  res -= (1LL) * cnt[a[x] ^ k];
}

void ins(int x) {
  res += (1LL) * cnt[a[x] ^ k];
  cnt[a[x]]++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].l--;
    q[i].idx = i;
  }
  block = sqrt(n + 1);
  sort(q + 1, q + 1 + m, cmpr);
  int curL = 0, curR = 0;
  for (int i = 1; i <= m; i++) {
    int L = q[i].l, R = q[i].r;
    while (curL < L) {
      del(curL++);
    }
    while (curL > L) {
      ins(--curL);
    }
    while (curR <= R) {
      ins(curR++);
    }
    while (curR > R + 1) {
      del(--curR);
    }
    ans[q[i].idx] = res;
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
