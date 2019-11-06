#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second

typedef long long ll;

const int N = 2e3 + 5;
const int M = N * (N + 1) / 2;

struct E {
    int u, v;
    long long w;
};

int n;
pair<int,int> p[N];
int c[N], k[N];
ll dist[N][N];
int par[N], sz[N];
vector<int> nodes;
vector<pair<int,int>> edges;
int len = 0;
ll cost = 0;
E edge[M];

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

void merge(int u, int v) {
    int pu = fpar(u); int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

bool cmpr(E a, E b) {
    return a.w < b.w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dist[i][j] = (1LL) * (k[i] + k[j]) * (1LL) * (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y));
            dist[j][i] = dist[i][j];
            edge[++len].u = i; edge[len].v = j; edge[len].w = dist[i][j];
        }
        edge[++len].u = 0; edge[len].v = i, edge[len].w = c[i];
    }
    sort(edge + 1, edge + 1 + len, cmpr);
    int cnt = 0, mins = 2e9, root = 0;
    for (int i = 1; i <= len; i++) {
        int u = edge[i].u, v = edge[i].v;
        int pu = fpar(u);
        int pv = fpar(v);
        if (pu != pv) {
            merge(pu, pv);
            if (u == 0) nodes.push_back(v);
            else edges.push_back({u, v});
            cost += edge[i].w;
        }
    }

    cout << cost << '\n';
    int kn = nodes.size();
    cout << kn << '\n';
    for (int i = 1; i <= kn; i++) {
        cout << nodes[i - 1] << (i == kn ? '\n' : ' ');
    }
    int klen = edges.size();
    cout << klen << '\n';
    for (int i = 1; i <= klen; i++) cout << edges[i - 1].x << " " << edges[i - 1].y << '\n';

    return 0;
}
