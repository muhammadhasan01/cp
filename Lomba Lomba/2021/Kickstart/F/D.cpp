#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nl(n), nr(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> nl[i] >> nr[i] >> a[i];
    }
    vector<vector<bool>> con(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        con[u][v] = con[v][u] = true;
    }
    vector<long long> sum(1 << n);
    vector<long long> value(1 << n);
    vector<bool> possible(1 << n);
    sum[0] = 1;
    possible[0] = true;
    long long ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            bool b = (mask & (1 << i));
            if (b) {
                value[mask] += a[i];
                int bmask = (mask ^ (1 << i));
                if (!possible[bmask]) {
                    continue;
                }
                long long bval = value[bmask];
                if (bmask == 0) {
                    possible[mask] = true;
                    sum[mask] += sum[bmask];
                    continue;
                }
                if (bval < nl[i] || bval > nr[i]) {
                    continue;
                }
                bool ok = false;
                for (int x = 0; x < n; x++) {
                    bool bb = (bmask & (1 << x));
                    if (bb) {
                        if (con[x][i]) {
                            ok = true;
                            break;
                        }
                    }
                }
                if (ok) {
                    possible[mask] = true;
                    sum[mask] += sum[bmask];
                }
            }
        }
        if (possible[mask] && value[mask] == k) {
            ans += sum[mask];
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}