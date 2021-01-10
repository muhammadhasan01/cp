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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int N = 200;

    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    vector<vector<int>> adj(N);
    vector<set<int>> group(N), igroup(N);
    vector<int> deg(N);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string str, u_s, v_s;
        for (int j = 0; j < 5; j++) {
            cin >> str;
            if (j == 0) {
                u_s = str;
            } else if (j == 4) {
                v_s = str;
            }
        }
        if (!mp.count(u_s)) mp[u_s] = ++cnt;
        if (!mp.count(v_s)) mp[v_s] = ++cnt;
        int u = mp[u_s], v = mp[v_s];
        adj[u].emplace_back(v);
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i < N; i++) {
        if (deg[i] == 0)
            q.emplace(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            group[v].emplace(u);
            for (int x : group[u])
                group[v].emplace(x);
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (group[i].empty()) continue;
        for (int j : group[i])
            igroup[j].emplace(i);
    }
    for (int i = 0; i < m; i++) {
        string str, u_s, v_s;
        for (int j = 0; j < 5; j++) {
            cin >> str;
            if (j == 0) {
                u_s = str;
            } else if (j == 4) {
                v_s = str;
            }
        }
        int u = mp[u_s], v = mp[v_s];
        if (group[v].find(u) != group[v].end()) {
            cout << "Fact" << '\n';
        } else if (igroup[v].find(u) != igroup[v].end()) {
            cout << "Alternative Fact" << '\n';
        } else {
            cout << "Pants on Fire" << '\n';
        }
    }

    return 0;
}