#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pre(n + 2);
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        if (cc == '+') {
            a[i] = 1;
        } else if (cc == '-') {
            a[i] = -1;
        }
        if (i % 2 == 0) {
            a[i] = -a[i];
        }
        pre[i] = pre[i - 1] + a[i];
    }
    map<int, set<int>> st;
    map<int, set<int>> vals;
    vals[pre[0]].emplace(0);
    for (int i = 1; i <= n; i++) {
        st[pre[i] + pre[i - 1]].emplace(i);
        vals[pre[i]].emplace(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int sz = r - l + 1;
        if (sz % 2 == 1) {
            cout << 1 << '\n';
            int val = pre[r] + pre[l - 1];
            auto& cur = st[val];
            auto it = cur.lower_bound(l);
            cout << *it << '\n';
        } else {
            int val = pre[r] - pre[l - 1];
            if (val == 0) {
                cout << 0 << '\n';
                continue;
            }
            cout << 2 << '\n';
            int pos_1 = *vals[val + pre[l - 1]].lower_bound(l);
            int pos_2 = *vals[val / 2 + pre[l - 1]].lower_bound(l);
            if (pos_1 > pos_2) {
                swap(pos_1, pos_2);
            }
            cout << pos_1 << ' ' << pos_2 << '\n';
        }
    }
}   

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}