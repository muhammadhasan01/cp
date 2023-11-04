#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> st;
    multiset<int> difs = {0};

    auto add = [&](int x) -> void {
        st.emplace(x);
        auto it = st.lower_bound(x);
        if (next(it) != st.end() && it != st.begin()) {
            int dif = *next(it) - *prev(it);
            difs.erase(difs.find(dif));
        }
        if (next(it) != st.end()) {
            int dif = *next(it) - *it;
            difs.emplace(dif);
        }
        if (it != st.begin()) {
            int dif = *it - *prev(it);
            difs.emplace(dif);
        }
    };

    auto remove = [&](int x) -> void {
        auto it = st.lower_bound(x);
        if (next(it) != st.end() && it != st.begin()) {
            int dif = *next(it) - *prev(it);
            difs.emplace(dif);
        }
        if (next(it) != st.end()) {
            int dif = *next(it) - *it;
            difs.erase(difs.find(dif));
        }
        if (it != st.begin()) {
            int dif = *it - *prev(it);
            difs.erase(difs.find(dif));
        }
        st.erase(x);
    };

    unordered_map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (++mp[a[i]] == 1) {
            add(a[i]);
        }
    }
    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++) {
        int i, x;
        cin >> i >> x;
        --i;
        if (--mp[a[i]] == 0) {
            remove(a[i]);
        }
        a[i] = x;
        if (++mp[a[i]] == 1) {
            add(a[i]);
        }
        cout << *st.rbegin() + *difs.rbegin() << " \n"[qq == q - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}