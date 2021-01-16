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

using pil = pair<int, long long>;

const long long INF = 1e18;
const int N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
long long ans[N];

struct T {
    int u;
    long long res;
    long long sum;
    long long maxi, mini;
    T(long long val, long long s, long long x, long long y, int u) :
        res(val), sum(s), maxi(x), mini(y), u(u) {}
    bool operator<(const T& o) const {
        return res > o.res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 2; i <= n; i++) {
        ans[i] = INF;
    }
    priority_queue<T> pq;
    pq.emplace(0, 0, -INF, INF, 1);
    while (!pq.empty()) {
        auto cc = pq.top();
        pq.pop();
        for (auto& e : adj[cc.u]) {
            int v = e.first;
            long long w = e.second;
            long long val = w + cc.sum - max(w, cc.maxi) + min(w, cc.mini);
            if (val < ans[v]) {
                ans[v] = val;
                T newCur = T(val, cc.sum + w, max(w, cc.maxi), min(w, cc.mini), v);
                pq.emplace(newCur);
            }
        } 
    }
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}