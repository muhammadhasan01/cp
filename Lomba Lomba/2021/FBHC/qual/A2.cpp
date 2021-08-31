#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 26;

void solve() {
    string str;
    cin >> str;
    vector<vector<int>> dist(K, vector<int>(K, INF));
    for (int i = 0; i < K; i++) {
        dist[i][i] = 0;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        int nu = u - 'A';
        int nv = v - 'A';
        dist[nu][nv] = 1;
    }
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = INF;
    for (int it = 0; it < K; it++) {
        int res = 0;
        for (char cc : str) {
            int num = cc - 'A';
            if (dist[num][it] == INF) {
                res = INF;
                break;
            }
            res += dist[num][it];
        }
        ans = min(ans, res);
    }
    if (ans == INF) {
        ans = -1;
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