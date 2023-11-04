#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, red;
    cin >> n >> red;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    red = min(red, n - red);
    if (2 * red == n) {
        cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
        return 0;
    }
    set<pair<long long, int>> st;
    vector<int> prv(n), nxt(n);
    iota(prv.begin(), prv.end(), -1);
    iota(nxt.begin(), nxt.end(), 1);
    for (int i = 1; i < n - 1; i++) {
        st.emplace(a[i] + a[i + 1], i);
    }
    long long ans = 0;
    for (int rep = 0; rep < red; rep++) {
        auto [val, i] = *st.rbegin();
        st.erase(*st.rbegin());
        ans += val;
        int l = prv[i], r = nxt[i];
        if (prv[l] != -1) {
            st.erase({a[l] + a[nxt[l]], l});
        }
        if (nxt[r] != n) {
            st.erase({a[r] + a[nxt[r]], r});
            prv[nxt[r]] = l;
        }
        nxt[l] = nxt[r];
        if (prv[l] != -1 && nxt[r] != n) {
            st.emplace(a[l] + a[nxt[l]], l);
        }
    }
    cout << ans << '\n';
    
    return 0;
}