#include <bits/stdc++.h>

using namespace std;

struct st {
  int l, r, idx;
};
int block;

bool cmpr(st a, st b) {
  if (a.l / block != b.l / block)
    return a.l / block < b.l / block;
  return a.r / block < b.r / block;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int curL = 0, curR = 0;
  for (int i = 1; i <= m; i++) {
    int L = q[i].l, R = q[i].R;
    while (curL < L) {
      remove(curL++);
    }
    while (curL > L) {
      insert(--curL);
    }
    while (curR <= R) {
      insert(curR++);
    }
    while (curR > R + 1) {
      remove(--curR);
    }
  }

  return 0;
}
