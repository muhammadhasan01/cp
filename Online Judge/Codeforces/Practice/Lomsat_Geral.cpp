#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int c[N], ans[N];
int tin[N], tout[N];
vector<int> g[N];
vector<int> eul;

struct st {
    int l, r, idx;
};

st p[N];
int block, maks;
int f[N];
unordered_map<int,int> gf, oc;
map<pair<int,int>, int> m;

void dfs(int u, int p = -1) {
    tin[u] = (int) eul.size();
    eul.push_back(u);
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = (int) eul.size();
    eul.push_back(u);
}

bool cmpr(st a, st b) {
    if (a.l / block != b.l / block)
        return a.l / block < b.l / block;
    return a.r / block < b.r / block;
}

void add(int x) {
    int col = c[eul[x]];
    oc[f[col]]--;
    f[col]++;
    oc[f[col]]++;
    pair<int,int> ccur = {f[col], col};
    int freq = ++m[ccur];
    if (freq == 1) {
        gf[f[col]] += col;
    }
    if (maks < f[col]) {
        maks = f[col];
    }
}

void remove(int x) {
    int col = c[eul[x]];
    if (f[col] == maks && oc[f[col]] == 1) {
        maks = f[col] - 1;
    }
    pair<int,int> ccur = {f[col], col};
    int freq = --m[ccur];
    if (freq == 0) {
        gf[f[col]] -= col;
    }
    oc[f[col]]--;
    f[col]--;
    oc[f[col]]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int len = eul.size();
    for (int i = 1; i <= n; i++) {
        p[i].l = tin[i], p[i].r = tout[i], p[i].idx = i;
    }
    block = sqrt(n + 1);
    sort(p + 1, p + 1 + n, cmpr);
    int curl = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        int l = p[i].l, r = p[i].r;
        while (curl < l) {
            remove(curl);
            curl++;
        }
        while (curl > l) {
            add(curl - 1);
            curl--;
        }
        while (curr <= r) {
            add(curr);
            curr++;
        }
        while (curr > r + 1) {
            remove(curr - 1);
            curr--;
        }
        ans[p[i].idx] = gf[maks];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
