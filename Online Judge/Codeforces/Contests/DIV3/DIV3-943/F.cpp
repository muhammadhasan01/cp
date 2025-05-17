#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i];
    }
    vector<pair<int, int>> queries(q + 1);
    vector<vector<int>> ql(n + 1);
    vector<vector<int>> qr(n + 1);
    vector<bool> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        auto& [l, r] = queries[i];
        cin >> l >> r;
        int XOR = pref[r] ^ pref[l - 1];
        if (XOR == 0) {
            ans[i] = true;
        } else {
            ql[l].emplace_back(XOR);
            qr[r].emplace_back(XOR);
        }
    }
    map<pair<int, int>, int> L;
    {
        map<int, int> mp;
        mp[0] = 0;
        int pre = 0;
        for (int i = 1; i <= n; i++) {
            pre ^= a[i];
            for (int XOR : qr[i]) {
                int need = XOR ^ pre;
                if (mp.find(need) != mp.end()) {
                    L[{i, XOR}] = mp[need] + 1;
                }
            }
            mp[pre] = i;
        }
    }
    map<pair<int, int>, int> R;
    {
        map<int, int> mp;
        mp[0] = n + 1;
        int suf = 0;
        for (int i = n; i >= 1; i--) {
            suf ^= a[i];
            for (int XOR : ql[i]) {
                int need = XOR ^ suf;
                if (mp.find(need) != mp.end()) {
                    R[{i, XOR}] = mp[need] - 1;
                }
            }
            mp[suf] = i;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i]) {
            continue;
        }
        auto& [l, r] = queries[i];
        int XOR = pref[r] ^ pref[l - 1];
        if (R.find({l, XOR}) == R.end() || L.find({r, XOR}) == L.end()) {
            continue;
        }
        int x = L[{r, XOR}];
        int y = R[{l, XOR}];
        ans[i] = (y < x);
    }
    for (int i = 1; i <= q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}