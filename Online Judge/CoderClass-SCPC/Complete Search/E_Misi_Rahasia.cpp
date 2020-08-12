#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m;
bool ok[N][N];
bool dp[(1 << N)][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ok[u][v] = ok[v][u] = 1;
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        int bit = __builtin_popcount(mask);
        if (bit == 1) continue;
        for ()
    }

    return 0;
}