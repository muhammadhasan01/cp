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

const int N = 2e5 + 5;

int n;
long long x, y;
vector<int> adj[N];
int ans = 0;

int dfs(int u, int p) {
    int left = 2;
    for (int v : adj[u]) {
        if (v == p) continue;
        int cur = dfs(v, u);
        if (left > 0 && cur == 1) {
            ans++;
            left--;
        }
    }
    return (left > 0 ? 1 : 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (x > y) {
        int maks = 0;
        for (int i = 1; i <= n; i++) {
            maks = max(maks, (int) adj[i].size());
        }
        cout << y * (n - 2) + (maks == n - 1 ? x : y) << '\n';
        return 0;
    }
    dfs(1, 1);
    cout << (n - 1 - ans) * y + ans * x << '\n';

    return 0;
}