#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
string b;
long long s;
long long ans;
long long n;
int par[N], sz[N];
bool vis[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> b >> s;
    bool flag = true;
    for (auto e : b) {
        if (e == 'E') {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << '\n';
        return 0;
    }
    n = b.length();
    if (n == s) {
        cout << 1 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    ans = n * s;
    b = '#' + b + '#';
    for (int i = 1; i <= n; i++) {
        if (b[i] == b[i + 1] && b[i] == 'P') merge(i, i + 1);
    }
    if (b[1] == b[n] && b[1] == 'P') merge(1, n);
    for (int i = 1; i <= n; i++) {
        if (b[i] == 'E') continue;
        int k = fpar(i);
        if (vis[k]) continue;
        vis[k] = 1;
        long long m = sz[k];
        long long c = min(s, m);
        long long cur = m * (m + 1) / 2 - (m - c) * (m - c + 1) / 2;
        ans -= cur;
    }
    cout << ans << '\n';

    return 0;
}
