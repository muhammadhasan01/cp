#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    n = n + n;
    vector<int> to(n, -1);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[u] = v;
        to[v] = u;
    }
    vector<int> pos(n, -1);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (to[i] != -1) {
            continue;
        }
        pos[len++] = i;
    }
    int m = len / 2;
    for (int i = 0; i < m; i++) {
        int u = pos[i], v = pos[i + m];
        to[u] = v;
        to[v] = u;
    }
    int ans = 0;
    vector<bool> done(n);
    for (int u = 0; u < n; u++) {
        if (done[u] || done[to[u]]) {
            continue;
        }
        int l = u, r = to[u];
        if (l > r) {
            swap(l, r);
        }
        done[l] = done[r] = true;
        for (int i = l + 1; i <= r - 1; i++) {
            if (l <= to[i] && to[i] <= r) {
                continue;
            }
            ans++;
        }
    }
    cout << ans / 2 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}