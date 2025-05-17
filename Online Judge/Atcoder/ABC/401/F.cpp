#include <bits/stdc++.h>

using namespace std;

const int B = 2;
const int N = 2e5 + 5;

int len[B];
vector<int> adj[B][N];
int fir[B][N];
int sec[B][N];
int ans[B][N];
long long suf[N];

int dfs(int tp, int u, int p) {
    int furthest = u;
    for (int v : adj[tp][u]) {
        if (v == p) {
            continue;
        }
        int res = dfs(tp, v, u);
        if (fir[tp][v] + 1 > fir[tp][u]) {
            sec[tp][u] = fir[tp][u];
            fir[tp][u] = fir[tp][v] + 1;
            furthest = res;
        } else {
            sec[tp][u] = max(sec[tp][u], fir[tp][v] + 1);
        }
    }
    return furthest;
};

void reroot(int tp, int u, int p, int up) {
    ans[tp][u] = max(fir[tp][u], up);
    for (int v : adj[tp][u]) {
        if (v == p) {
            continue;
        }
        int cur = fir[tp][u] == fir[tp][v] + 1 ? sec[tp][u] : fir[tp][u];
        reroot(tp, v, u, max(up, cur) + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < B; i++) {
        cin >> len[i];
        for (int j = 1; j < len[i]; j++) {
            int u, v;
            cin >> u >> v;
            adj[i][u].emplace_back(v);
            adj[i][v].emplace_back(u);
        }
    }
    int mx = 0;
    for (int i = 0; i < B; i++) {
        int u = dfs(i, 1, 1);
        for (int j = 1; j <= len[i]; j++) {
            fir[i][j] = 0;
            sec[i][j] = 0;
        }
        dfs(i, u, u);
        mx = max(mx, fir[i][u]);
        reroot(i, u, u, 0);
    }
    sort(ans[1] + 1, ans[1] + 1 + len[1]);
    for (int i = len[1]; i >= 1; i--) {
        suf[i] = ans[1][i];
        if (i + 1 <= len[1]) {
            suf[i] += suf[i + 1];
        }
    }
    long long sum = 0;
    for (int u = 1; u <= len[0]; u++) {
        int l = 1, r = len[1], at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ans[0][u] + ans[1][mid] + 1 > mx) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) {
            sum += 1LL * mx * len[1];
            continue;
        }
        sum += 1LL * mx * (at - 1);
        int cnt = len[1] - at + 1;
        sum += suf[at];
        sum += 1LL * cnt * (1 + ans[0][u]);
    }
    cout << sum << '\n';
    
    return 0;
}