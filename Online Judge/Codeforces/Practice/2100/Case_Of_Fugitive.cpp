#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<pll, int> plli;

const int N = 2e5 + 5;
const ll INF = 2e18;

int n, m;
plli p[N];
pli a[N];
int ans[N];
set<pii> st;
int ri[N];
vector<int> vle[N], vri[N];

void dismiss() {
  puts("No");
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  n--;
  ll l1, r1, l2, r2;
  cin >> l2 >> r2;
  for (int i = 1; i <= n; i++) {
    cin >> l1 >> r1;
    p[i] = {{l1 - r2, r1 - l2}, i};
    l2 = l1, r2 = r1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  if (m < n) {
    dismiss();
  }
  sort(p + 1, p + 1 + n);
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= n; i++) {
    int l1 = 1, r1 = m, p1 = m + 1;
    while (l1 <= r1) {
      int mid = (l1 + r1) >> 1;
      if (a[mid].first >= p[i].first.first) {
        r1 = mid - 1;
        p1 = mid;
      } else {
        l1 = mid + 1;
      }
    }
    int l2 = 1, r2 = m, p2 = -1;
    while (l2 <= r2) {
      int mid = (l2 + r2) >> 1;
      if (p[i].first.second >= a[mid].first) {
        l2 = mid + 1;
        p2 = mid;
      } else {
        r2 = mid - 1;
      }
    }
    if (p1 > p2) dismiss();
    ri[i] = p2;
    vle[p1].push_back(i);
    vri[p2 + 1].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    for (auto e : vle[i]) st.insert({ri[e], e});
    for (auto e : vri[i]) st.erase({ri[e], e});
    auto it = st.lower_bound({i, 0});
    if (it == st.end()) continue;
    ans[p[it -> second].second] = a[i].second;
    st.erase(it);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) dismiss();
  }
  cout << "Yes" << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
