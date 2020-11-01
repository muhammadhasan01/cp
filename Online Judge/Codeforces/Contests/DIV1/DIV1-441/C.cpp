#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

const int N = 1e5 + 5;

int n, m;
int lens[N];
vector<int> adj[N], res[N];
bool need[N], vis[N];

void dismiss() {
    cout << "No" << '\n';
    exit(0);
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> lens[i];
        res[i].resize(lens[i] + 1);
        for (int j = 1; j <= lens[i]; j++) {
            cin >> res[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        int j = 1;
        for ( ; j <= min(lens[i], lens[i + 1]); j++) {
            int x = res[i][j], y = res[i + 1][j];
            if (x == y) continue;
            if (x < y) {
                adj[y].emplace_back(x);
            } else {
                need[x] = 1;
            }
            break;
        }
        if (j == lens[i + 1] + 1 && lens[i] > lens[i + 1]) dismiss();
    }
    for (int i = 1; i <= m; i++) {
        if (need[i]) dfs(i);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= min(lens[i], lens[i + 1]); j++) {
            int x = res[i][j], y = res[i + 1][j];
            if (x == y) continue;
            if (vis[x]) x -= m;
            if (vis[y]) y -= m;
            if (x > y) dismiss();
            break;
        }
    }
    vector<int> answer;
    for (int i = 1; i <= m; i++) {
        if (vis[i]) answer.emplace_back(i);
    }
    cout << "Yes" << "\n";
    int len = answer.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << answer[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}