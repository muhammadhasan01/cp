#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<vector<long long>> dist(n, vector<long long>(n, -1));
    for (int i = 0; i < m; i++) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        --u, --v;
        dist[u][v] = d;
        dist[v][u] = d;
    }
    vector<set<long long>> st(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> bits;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bits.emplace_back(i);
            }
         }
         int len = (int) bits.size();
         if (len == 1) {
            st[mask].emplace(0LL);
         } else {
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    int x = bits[i];
                    int y = bits[j];
                    if (dist[x][y] == -1) {
                        continue;
                    }
                    int bmask = (mask ^ (1 << x));
                    for (auto& val : st[bmask]) {
                        st[mask].emplace((val + dist[x][y]) % k); 
                    }
                }
            }
         }
    }
    cout << *st[(1 << n) - 1].begin() << '\n';
    
    return 0;
}