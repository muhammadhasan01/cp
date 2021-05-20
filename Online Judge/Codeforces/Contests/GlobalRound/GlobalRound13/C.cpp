#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n;
int s[N];
int par[N];

int fpar(int u) {
    return (par[u] == u ? u : par[u] = fpar(par[u]));
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        par[i] = i;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] > n - i) {
            ans += (s[i] - (n - i));
            s[i] = n - i;
        }
        while (s[i] > 1) {
            int j = i;
            while (j <= n) {
                int pos = min(n + 1, j + s[j]);
                pos = fpar(pos);
                s[j] = max(1, s[j] - 1);
                if (s[j] == 1) merge(j + 1, j);
                j = pos;
            }
            ++ans;
        }
    }
    if (s[n] > 1) ans += (s[n] - 1);
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