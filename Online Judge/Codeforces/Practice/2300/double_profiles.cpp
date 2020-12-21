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

const int N = 1e6 + 5;
const long long M = 1e9 + 7;
const int prime[] = {29, 31};

int n, m;
vector<int> adj[N];
bool vis[N];
int nxt[N];
long long pre[N][2];

void init() {
    pre[0][0] = pre[0][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            pre[i][j] = (pre[i - 1][j] * prime[j]) % M;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (n <= 2) {
        cout << n - 1 << '\n';
        return 0;
    }
    long long ans = 0;

    auto addAnswer = [&]() -> void {
        map<pair<long long, long long>, int> mp;
        for (int i = 1; i <= n; i++) {
            vector<long long> cur(2);
            for (int it = 0; it < 2; it++) {
                for (int j = 0; j < (int) adj[i].size(); j++) {
                    int v = adj[i][j];
                    cur[it] = (cur[it] + (1LL) * v * pre[j][it]) % M;
                }
            }
            ans += mp[make_pair(cur[0], cur[1])]++;
        }
    };

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    addAnswer();
    for (int i = 1; i <= n; i++) {
        adj[i].emplace_back(i);
        sort(adj[i].begin(), adj[i].end());
    }
    addAnswer();
    cout << ans << '\n';

    return 0;
}