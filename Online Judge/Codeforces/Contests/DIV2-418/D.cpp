#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const long double PI = acos(-1);

struct st {
    long double x, y, r;
    long double area;
    bool operator<(const st& other) {
        return r < other.r;
    }
};

int n;
st p[N];
vector<int> g[N];
int par[N];
long double ans;

bool check(st a, st b) {
    long double x = abs(a.x - b.x);
    long double y = abs(a.y - b.y);
    return a.r * a.r > x * x + y * y;
}

void dfs(int u, int h) {
    if (h) ans += p[u].area;
    else ans -= p[u].area;
    for (auto v : g[u]) {
        dfs(v, 1 - h);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].r;
        p[i].area = (PI * p[i].r * p[i].r);
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].r < p[j].r && check(p[j], p[i])) {
                par[i] = j;
            }
            if (par[i]) break;
        }
    }
    vector<bool> vis(n + 1);
    vis[0] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (!vis[cur]) {
            if (par[cur]) g[par[cur]].emplace_back(cur);
            vis[cur] = 1;
            cur = par[cur];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!par[i]) {
            ans += (p[i].area * 2);
            dfs(i, 0);
        }
    }
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}