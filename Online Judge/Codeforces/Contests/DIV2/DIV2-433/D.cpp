#include <bits/stdc++.h>

using namespace std;

struct st {
  int d, f, t, c;
  bool operator<(const st& other) {
    return (d < other.d);
  }
};

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const long long INF = 1e18;

int n, m, k;
st p[N];
int suf[M];
int pre[M];
long long ressuf[M];
long long respre[M];
priority_queue<int, vector<int>, greater<int>> pq_pre[M];
priority_queue<int, vector<int>, greater<int>> pq_suf[M];
long long ans = INF;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> p[i].d >> p[i].f >> p[i].t >> p[i].c;
  }
  sort(p + 1, p + 1 + m);
  for (int i = m; i >= 1; i--) {
    if (p[i].t == 0) continue;
    if (pq_suf[p[i].t].empty()) {
      ressuf[p[i].d] += (1LL) * (p[i].c);
      suf[p[i].d]++;
    } else {
      int cur = pq_suf[p[i].t].top();
      if (p[i].c < cur) {
        ressuf[p[i].d] += (1LL) * (p[i].c - cur);
      }
    }
    pq_suf[p[i].t].push(p[i].c);
  }
  for (int i = M - 1; i >= 0; i--) {
    suf[i] += suf[i + 1];
    ressuf[i] += ressuf[i + 1];
  }
  for (int i = 1; i <= m; i++) {
    if (p[i].f == 0) continue;
    if (pq_pre[p[i].f].empty()) {
      respre[p[i].d] += (1LL) * (p[i].c);
      pre[p[i].d]++;
    } else {
      int cur = pq_pre[p[i].f].top();
      if (p[i].c < cur) {
        respre[p[i].d] += (1LL) * (p[i].c - cur);
      }
    }
    pq_pre[p[i].f].push(p[i].c);
  }
  for (int i = 1; i < M; i++) {
    pre[i] += pre[i - 1];
    respre[i] += respre[i - 1];
  }
  for (int i = 1; i < M; i++) {
    if (i + k < M && pre[i - 1] == n && suf[i + k] == n) {
      ans = min(ans, respre[i - 1] + ressuf[i + k]);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';

  return 0;
}