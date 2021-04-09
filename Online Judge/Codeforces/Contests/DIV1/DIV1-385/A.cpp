#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m, k;
bool government[N];
int par[N], cnt[N], sz[N];

int fpar(int u) {
    return (par[u] == u ? u : par[u] = fpar(par[u]));
}

bool merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return false;
    if (cnt[pu] < cnt[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    cnt[pu] += cnt[pv];
    par[pv] = pu;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        government[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
        sz[fpar(u)]++;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        int p = fpar(i);
        if (p == i) {
            v.emplace_back(i);
        }
        if (government[i]) {
            government[p] = true;
        }
    }
    int maks = -1, pos = -1;
    for (int x : v) {
        if (government[x]) {
            if (cnt[x] > maks) {
                maks = cnt[x];
                pos = x;
            } else if (cnt[x] == maks && sz[x] < sz[pos]) {
                pos = x;
            }
        }
    }
    long long ans = 0;
    for (int x : v) {
        if (government[x]) {
            if (x == pos) continue;
            ans += 1LL * cnt[x] * (cnt[x] - 1) / 2 - sz[x];
        } else {
            merge(pos, x);
            ++ans;
            sz[fpar(pos)]++;
        }
    }
    pos = fpar(pos);
    ans += 1LL * cnt[pos] * (cnt[pos] - 1) / 2 - sz[pos];
    cout << ans << '\n';

    return 0;
}