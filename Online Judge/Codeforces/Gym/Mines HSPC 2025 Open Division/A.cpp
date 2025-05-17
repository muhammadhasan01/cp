#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> solve_graph(int n, const vector<ll>& adj) {
    int n1 = n / 2, n2 = n - n1;
    int S1 = 1 << n1;
    int S2 = 1 << n2;
    vector<ll> adj1(n1, 0), ban2(n1, 0);
    for (int u = 0; u < n1; u++) {
        adj1[u] = adj[u] & ((1LL << n1) - 1);
        ban2[u] = (adj[u] >> n1) & ((1LL << n2) - 1);
    }
    vector<ll> adj2(n2, 0);
    for (int v2 = 0; v2 < n2; v2++) {
        int v = n1 + v2;
        adj2[v2] = (adj[v] >> n1) & ((1LL << n2) - 1);
    }
    vector<char> good2(S2, 0);
    vector<int> pop2(S2, 0);
    good2[0] = 1;
    for (int mask = 1; mask < S2; mask++) {
        int b = __builtin_ctz(mask);
        int prev = mask ^ (1 << b);
        pop2[mask] = pop2[prev] + 1;
        good2[mask] = good2[prev] && ((adj2[b] & prev) == 0);
    }
    vector<vector<int>> f(n2 + 1, vector<int>(S2, 0));
    for (int mask = 0; mask < S2; mask++) {
        if (good2[mask]) {
            f[pop2[mask]][mask] = 1;
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int mask = 0; mask < S2; mask++) {
            if (mask & (1 << i)) {
                int prev = mask ^ (1 << i);
                for (int j = 0; j <= n2; j++) {
                    f[j][mask] += f[j][prev];
                }
            }
        }
    }
    vector<ll> ans(n + 1, 0);
    for (int mask1 = 0; mask1 < S1; mask1++) {
        bool ok = true;
        ll forb = 0;
        int cnt1 = 0;
        int m = mask1;
        while (m) {
            int b = __builtin_ctz(m);
            m ^= (1 << b);
            cnt1++;
            if (adj1[b] & mask1) {
                ok = false;
                break;
            }
            forb |= ban2[b];
        }
        if (!ok) continue;
        int allowed = ((S2 - 1) ^ int(forb));
        for (int j = 0; j <= n2; j++) {
            int ways2 = f[j][allowed];
            if (ways2) {
                ans[cnt1 + j] += ways2;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> adj(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a] |= 1LL << b;
        adj[b] |= 1LL << a;
    }
    auto ans = solve_graph(n, adj);
    for (int k = 0; k <= n; k++) {
        cout << ans[k] << " \n"[k == n];
    }

    return 0;
}