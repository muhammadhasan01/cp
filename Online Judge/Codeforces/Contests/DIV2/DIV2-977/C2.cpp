#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> ord(n + 1);
    for (int i = 0; i < n; i++) {
        ord[a[i]] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        b[i] = ord[b[i]];
    }
    vector<set<int>> st(n + 1);
    for (int i = 1; i <= n; i++) {
        st[i].emplace(INF + i);
    }
    for (int i = 0; i < m; i++) {
        st[b[i]].emplace(i);
    }

    auto check = [&](int i) -> bool {
        if (i >= n || i <= 0) {
            return false;
        }
        return *st[i].begin() < *st[i + 1].begin();
    };

    int cnt = 0;
    for (int i = 1; i + 1 <= n; i++) {
        if (check(i)) {
            ++cnt;
        }
    }
    cout << (cnt == n - 1 ? "YA" : "TIDAK") << '\n';
    while (q--) {
        int s, t;
        cin >> s >> t;
        t = ord[t];
        --s;
        if (b[s] != t) {
            map<int, bool> mp;
            mp[b[s]] = check(b[s]);
            mp[b[s] - 1] = check(b[s] - 1);
            mp[t] = check(t);
            mp[t - 1] = check(t - 1);

            auto update = [&](int x) -> void {
                if (mp.count(x) && mp[x] != check(x)) {
                    cnt += (mp[x] ? -1 : 1);
                    mp.erase(x);
                }
            };

            st[b[s]].erase(s);
            st[t].emplace(s);
            update(b[s]);
            update(b[s] - 1);
            update(t);
            update(t - 1);
            b[s] = t;
        }
        cout << (cnt == n - 1 ? "YA" : "TIDAK") << '\n';
    }
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