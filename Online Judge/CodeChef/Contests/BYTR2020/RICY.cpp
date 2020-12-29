#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
int nxt[N], cnt[N];
long long dp[N];

void init() {
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        cnt[i] = 0;
    }
}

long long DP(int x) {
    if (x == n + 1) return 0;
    if (dp[x] != -1) return dp[x];
    int y = nxt[x];
    int total = cnt[y - 1] - cnt[x - 1];
    dp[x] = (1LL) * total * a[x] + DP(y);
    return dp[x];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    init();
    stack<int> st;
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        nxt[i] = (st.empty() ? n + 1 : st.top());
        st.emplace(i);
    }
    for (int i = 1; i <= m; i++) {
        cnt[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    long long answer = 0;
    for (int i = 1; i <= m; i++) {
        answer += DP(b[i]);
    }
    cout << answer << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}