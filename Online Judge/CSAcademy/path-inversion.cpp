#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100000;

const int MOD = int(1e9) + 7;

int n, k;
vector<int> g[N];
int sz[N];
bool used[N];
LL ans;

inline void calcSizes(int v, int p) {
    sz[v] = 1;
    for (int &to : g[v]) if (used[to] && to != p) {
        calcSizes(to, v);
        sz[v] += sz[to];
    }
}

int cnt[N];

int delta;
void dfs(int v, int par, int dist) {
    cnt[dist] += delta;
    for (int to : g[v]) if (used[to] && to != par) {
        dfs(to, v, dist + 1);
    }
}

void dfs2(int v, int par, int dist) {
    if (dist <= k) {
        ans += cnt[k - dist];
    }
    for (int to : g[v]) if (used[to] && to != par) {
        dfs2(to, v, dist + 1);
    }
}

void solve(int v) {
    cnt[0] = 2;
    delta = 1;
    for (int to : g[v]) if (used[to]) {
        dfs(to, v, 1);
    }
    for (int to : g[v]) if (used[to]) {
        delta = -1;
        dfs(to, v, 1);

        dfs2(to, v, 1);

        delta = 1;
        dfs(to, v, 1);
    }
    delta = -1;
    for (int to : g[v]) if (used[to]) {
        dfs(to, v, 1);
    }
}

void cd(int v, int p) {
    calcSizes(v, -1);
    int tot = sz[v];
    bool ok = false;
    int pp = -1;
    while (!ok) {
        ok = true;
        for (int to : g[v]) if (used[to] && to != pp && sz[to] * 2 > tot) {
            pp = v;
            v = to;
            ok = false;
            break;
        }
    }
    solve(v);
    used[v] = false;
    for (int to : g[v]) if (used[to]) {
        cd(to, v);
    }
}

int solve() {
    ans = 0;
    forn(i, n) used[i] = true;
    cd(0, -1);
    assert(ans % 2 == 0);
    ans /= 2;
    return (LL)k * (k + 1) / 2 % MOD * (ans % MOD) % MOD;
}

void readTest() {
    scanf("%d%d", &n, &k);
    forn(i, n) g[i].clear();
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
}

int main() {
    readTest();
    cout << solve() << endl;
    return 0;
}
