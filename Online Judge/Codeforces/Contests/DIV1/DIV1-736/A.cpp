#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, q;
int deg[N];
int cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        deg[u]++, deg[v]++;
        cnt[v]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == cnt[i]) {
            ++ans;
        }
    }
    auto add = [&](int u, int v) -> void {
        if (u > v) {
            swap(u, v);
        }
        if (deg[u] == cnt[u]) {
            --ans;
        }
        deg[u]++, deg[v]++;
        cnt[v]++;
    };
    auto remove = [&](int u, int v) -> void {
        if (u > v) {
            swap(u, v);
        }
        deg[u]--, deg[v]--;
        cnt[v]--;
        if (deg[u] == cnt[u]) {
            ++ans;
        }
    };
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int u, v;
            cin >> u >> v;
            add(u, v);
        } else if (tp == 2) {
            int u, v;
            cin >> u >> v;
            remove(u, v);
        } else if (tp == 3) {
            cout << ans << '\n';
        }
    }

    return 0;
}