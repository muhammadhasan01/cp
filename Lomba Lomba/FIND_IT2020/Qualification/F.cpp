#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int INF = 2e9;

int n, x, m;
st a[N];
int cnt[N];

struct st {
  int p, q;
  bool operator<(const st& other) {
    return (q - p < other.p - other.q);
  }
};

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].p >> a[i].q;
  }
  sort(a + 1, a + 1 + m);
  

  return 0;
}