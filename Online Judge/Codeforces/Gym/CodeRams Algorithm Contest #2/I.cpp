// author: ACMHIT
#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e5 + 5;

struct edge {
    int b, l;
} g[N << 1];

int h[N], t, dfn[N], y, low[N], ans[N];

void addedge(int a, int b) {
    g[++t] = (edge) {b, h[a]};
    h[a] = t;
}

void dfs(int u, int fa) {
    dfn[u] = low[u] = ++t;
    if (u == y) {
        ans[u] = 1;
    }
    for (int i = h[u]; i > 0; i = g[i].l) {
        if (!dfn[g[i].b]) {
            dfs(g[i].b, u);
            low[u] = min(low[u], low[g[i].b]);
            if (dfn[g[i].b] <= dfn[y] && dfn[u] <= low[g[i].b]) {
                ans[u] = 1;
            }
        } else if (fa != g[i].b) {
            low[u] = min(low[u], dfn[g[i].b]);
        }
    }
    if (!fa) {
        ans[u] = 1;
    }
}

int main() {
    int n, m, x, i, j, k;
    scanf("%d%d%d%d", & n, & m, & x, & y);
    while (m--) {
        scanf("%d%d", & k, & i);
        k--;
        while (k--) {
            scanf("%d", & j);
            addedge(i, j);
            addedge(j, i);
            i = j;
        }
    }
    dfs(x, t = 0);
    for (i = 1; i <= n; i++) {
        printf("%d", !ans[i]);
    }
    return 0;
}