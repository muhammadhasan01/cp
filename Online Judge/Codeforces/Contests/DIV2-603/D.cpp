#include <bits/stdc++.h>

using namespace std;

const int M = 30;
const int N = 2e5 + 5;
int n;
string s[N];
int par[M], sz[M];
bool vis[M];
int ans;

int fpar(int x) {
    return (par[x] == x ? x : fpar(par[x]));
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

    cin >> n;
    for (int i = 0; i < M; i++) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < (int) s[i].size() - 1; j++) {
            int u = s[i][j] - 'a';
            int v = s[i][j + 1] - 'a';
            merge(u, v);
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = fpar(s[i][0] - 'a');
        if (vis[k]) continue;
        vis[k] = 1;
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
