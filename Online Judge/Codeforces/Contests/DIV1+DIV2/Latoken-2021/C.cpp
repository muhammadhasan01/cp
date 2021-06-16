#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 4e5 + 5;

int n;
int pos[N];
int par[N], sz[N];

int fpar(int x) {
    return (x == par[x] ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        merge(i, pos[x]);
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i == fpar(i)) {
            ans = (2 * ans) % M;
        }
    }
    cout << ans << '\n';
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