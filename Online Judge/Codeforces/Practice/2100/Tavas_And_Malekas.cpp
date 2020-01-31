#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1e9 + 7;

int n, m;
string p;
int y[N];
int cnt[N];

long long fast(long long x, int y) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return (ret % M + M) % M;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  cin >> p;
  for (int i = 1; i <= m; i++) {
    cin >> y[i];
  }
  int len = p.size();
  vector<int> lps(len);
  for (int i = 1, j = 0; i < len; i++) {
    j = lps[i - 1];
    while (j > 0 && p[i] != p[j]) j = lps[j - 1];
    if (p[i] == p[j]) j++;
    lps[i] = j;
  }
  set<int> st;
  int cur = len - 1;
  while (cur >= 0) {
    if (lps[cur] == 0) break;
    st.insert(len - lps[cur]);
    cur = lps[cur] - 1;
  }
  for (int i = 1; i <= m; i++) {
    cnt[y[i]]++;
    cnt[y[i] + len]--;
    if (i == 1) continue;
    int dif = y[i] - y[i - 1];
    if (dif >= len) continue;
    if (st.find(dif) != st.end()) continue;
    cout << 0 << '\n';
    return 0;
  }
  int zero = 0;
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
    if (cnt[i] == 0) zero++;
  }
  cout << fast(26, zero) << '\n';

  return 0;
}
