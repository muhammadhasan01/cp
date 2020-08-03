#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

const int N = 1e5 + 5;
const int M = 1e9 + 7;

int n;
int x[N], y[N];
int par[N];
unordered_map<int, int> mx, my;
vector<pair<int, int>> v[N][2];
set<int> mpx[N], mpy[N];
vector<int> adj[N];
int pre[N], col[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void init() {
    pre[0] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = (2 * pre[i - 1]) % M;
        par[i] = i;
    }
}

bool dfs(int u, int p) {
    col[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (col[v] == 0) {
            if (dfs(v, u)) return true;
        } else if (col[v] == 1) {
            return true;
        }
    }
    col[u] = 2;
    return false;
}

int main() {
    inpos(n);
    init();
    for (int i = 1; i <= n; i++) {
        inpos(x[i]), inpos(y[i]);
        int cx = mx[x[i]];
        if (cx == 0) {
            mx[x[i]] = cx = i;
        } else {
            merge(i, cx);
        }
        int cy = my[y[i]];
        if (cy == 0) {
            my[y[i]] = cy = i;
        } else {
            merge(i, cy);
        }
        v[cx][0].emplace_back(y[i], i);
        v[cy][1].emplace_back(x[i], i);
    }
    for (int i = 1; i <= n; i++) {
        for (int it = 0; it < 2; it++) {
            vector<pair<int, int>>& cur = v[i][it];
            int len = cur.size();
            if (len < 2) continue;
            sort(cur.begin(), cur.end());
            for (int j = 0; j < len; j++) {
                if (j > 0)
                    adj[cur[j].second].emplace_back(cur[j - 1].second);
                if (j < len - 1)
                    adj[cur[j].second].emplace_back(cur[j + 1].second);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int p = fpar(i);
        mpx[p].emplace(x[i]);
        mpy[p].emplace(y[i]);
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        if (fpar(i) != i) continue;
        long long cur = pre[(int) mpx[i].size()];
        cur = (cur * pre[(int) mpy[i].size()]) % M;
        if (!dfs(i, i))
            cur = ((cur - 1) % M + M) % M;
        ans = (ans * cur) % M;
    }
    outpos(ans);

    return 0;
}