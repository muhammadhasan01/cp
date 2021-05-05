#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int par[N];
bool done[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    par[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        merge(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int pi = fpar(i);
        if (done[pi]) continue;
        done[pi] = true;
        ans++;
    }
    cout << ans << '\n';

    return 0;
}