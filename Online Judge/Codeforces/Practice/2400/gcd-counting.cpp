#include <bits/stdc++.h>

using namespace std;

const int M = 2e5;
const int N = M + 10;

int n;
int a[N];
int nodes, chosen;
vector<int> adj[N];
vector<int> divisors[N];
vector<int> cnts;
int sz[N];
int cnt[N];
bool checked[N];
long long ans[N];

void calc_sizes(int u, int p) {
    nodes++; sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        calc_sizes(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        if (sz[v] > nodes) return centroid(v, u);
    }
    return u;
}

void add_cnt(int u, int p, int g) {
    cnts.emplace_back(g);
    cnt[g]++;
    for (int v : adj[u]) {
        if (v == p || checked[v]) {
            continue;
        }
        add_cnt(v, u, __gcd(g, a[v]));
    }
}

void solve(int u) {
    chosen = a[u];
    cnt[chosen] += 2;
    ans[chosen] += 2;
    vector<vector<pair<int, int>>> comp;
    for (int v : adj[u]) {
        if (checked[v]) {
            continue;
        }
        cnts.clear();
        add_cnt(v, u, __gcd(a[u], a[v]));
        vector<pair<int, int>> cur;
        sort(cnts.begin(), cnts.end());
        int len = cnts.size();
        for (int i = 0, f = 1; i < len; i++) {
            if (i + 1 < len && cnts[i] == cnts[i + 1]) {
                f += 1;
                continue;
            }
            cur.emplace_back(cnts[i], f);
            f = 1;
        }
        comp.emplace_back(cur);
    }
    int it = 0;
    for (int v : adj[u]) {
        if (checked[v]) {
            continue;
        }
        auto& cur = comp[it++];
        for (auto& [g, c] : cur) {
            cnt[g] -= c;
        }
        for (auto& [g, c] : cur) {
            for (int div : divisors[chosen]) {
                if (cnt[div] == 0) {
                    continue;
                }
                int val = __gcd(g, div);
                ans[val] += 1LL * c * cnt[div];
            }
        }
        for (auto& [g, c] : cur) {
            cnt[g] += c;
        }
    }
    for (int val : divisors[chosen]) {
        cnt[val] = 0;
    }
}

void decompose(int u) {
    nodes = 0;
    calc_sizes(u, u);
    nodes /= 2;
    int v = centroid(u, u);
    checked[v] = 1;
    solve(v);
    for (auto w : adj[v]) {
        if (checked[w]) continue;
        decompose(w);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    decompose(1);
    for (int i = 1; i <= M; i++) {
        if (ans[i] == 0) {
            continue;
        }
        cout << i << ' ' << ans[i] / 2 << '\n';
    }

    return 0;
}