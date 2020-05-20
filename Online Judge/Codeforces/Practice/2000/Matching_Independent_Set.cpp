#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int tc;
int n, m;
int vis[N];
int ans[N], res[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        n = 3 * n;
        fill(vis, vis + 3 * n + 1, 0);
        int lans = 0, lres = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            if (vis[u] || vis[v]) continue;
            ans[++lans] = i;
            vis[u] = vis[v] = 1;
        }
        for (int i = 1; i <= 3 * n; i++) {
            if (!vis[i]) {
                res[++lres] = i;
            }
        }
        n /= 3;
        if (lans >= n) {
            cout << "Matching" << '\n';
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << (i == n ? '\n' : ' ');
            }
        } else {
            cout << "IndSet" << '\n';
            for (int i = 1; i <= n; i++) {
                cout << res[i] << (i == n ? '\n' : ' ');
            }
        }
    }

    return 0;
}