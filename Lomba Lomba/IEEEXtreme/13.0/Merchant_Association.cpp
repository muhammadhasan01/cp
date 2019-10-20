#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k;
vector<int> g[N];
int p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        
    }

    return 0;
}
