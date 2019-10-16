#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int SN = 200;
const int inf = 1e7;
int n;
bool a[N][65];
long long cnt[65];
pair<int,int> p[65];
vector<int> g[N];
int vis[SN], hi[SN], oc[N];
map<pair<int,int>, int> m;

int ans = inf;

void dfs(int u, int v, int h) {
    vis[u] = 1;
    hi[u] = ++h;
    for (auto e : g[u]) {
        if (e == v) continue;
        if (vis[e] == 0) {
            dfs(e, u, h);
        } else if(vis[e] == 1){
            ans = min(ans, hi[u] - hi[e] + 1);
        }
    }
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        for (int j = 60; j >= 0; j--) {
            a[i][j] = x & (1LL << j);
            if (a[i][j]) cnt[j]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 60; j >= 0; j--) {
            if (a[i][j] && p[j].first == 0) {
                p[j].first = i;
            } else if (a[i][j]) {
                p[j].second = i;
            }
            if (cnt[j] >= 3) {
                cout << 3 << '\n';
                return 0;
            }
        }
    }

    int t = 0;
    for (int j = 0; j <= 60; j++) {
        if (p[j].second > 0 && m[p[j]] == 0) {
            m[p[j]]++;
            int tp = p[j].first, tq = p[j].second;
            if (oc[tp] == 0) oc[tp] = ++t;
            if (oc[tq] == 0) oc[tq] = ++t;
            g[oc[tp]].push_back(oc[tq]);
            g[oc[tq]].push_back(oc[tp]);
        }
    }

    for (int i = 1; i <= t; i++) {
        dfs(i, i, 0);
        for (int j = 1; j <= t; j++) {
            vis[j] = 0, hi[j] = 0;
        }
    }

    if (ans == inf) ans = -1;

    cout << ans << "\n";


    return 0;
}
