#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct DSU {
    int n;
    vector<int> par;
    
    DSU(int _n) : n(_n + 1), par(_n + 1) {
        iota(par.begin(), par.end(), 0);
    }

    int fpar(int x) {
        return (par[x] == x ? x : fpar(par[x]));
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        par[pv] = pu;
        return true;
    }
};

int n;
pair<int, int> a[N];
int b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }
    DSU lft(n + 5), rgt(n + 5);
    sort(a + 1, a + 1 + n);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int pos = a[i].second;
        int l = lft.fpar(pos - 1);
        if (l >= 1) {
            st.emplace(abs(b[l] - b[pos]));
        }
        lft.merge(l, pos);
        int r = rgt.fpar(pos + 1);
        if (r <= n) {
            st.emplace(abs(b[r] - b[pos]));
        }
        rgt.merge(r, pos);
    }
    cout << st.size() << '\n';
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