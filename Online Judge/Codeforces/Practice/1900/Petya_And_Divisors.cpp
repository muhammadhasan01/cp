#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, block;
vector<int> v[N];
int ans[N];
int cnt[N];

struct query {
  int l, r;
  bool operator<(const query& q) {
    if (l / block == q.l / block) return r / block < q.r / block;
    return l / block < q.l / block;
  }
};

query q[N];

void addz(int pos) {
  for (auto e : v[pos]) cnt[e]++;
}

void delz(int pos) {
  for (auto e : v[pos]) cnt[e]--;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  block = sqrt(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        v[i].push_back(j);
        if (j * j != x) v[i].push_back(x / j);
      }
    }
    if (i > 1) q[i - 1] = {i - y, i - 1};
  }
  sort(q + 1, q + n);
  int curL = 0, curR = 0;
  for (int i = 1; i < n; i++) {
    int le = q[i].l, re = q[i].r;
    while (curL < le) {
      delz(curL++);
    }
    while (curL > le) {
      addz(--curL);
    }
    while (curR <= re) {
      addz(curR++);
    }
    while (curR > re + 1) {
      delz(--curR);
    }
    int res = 0;
    for (auto e : v[re + 1]) {
      if (cnt[e] == 0) res++;
    }
    ans[re + 1] = res;
  }
  ans[1] = (int) v[1].size();
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
