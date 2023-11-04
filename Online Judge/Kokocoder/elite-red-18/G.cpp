#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    int last = INF;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (last > a[i]) {
            last = a[i];
            st.emplace(i);
        }
    }
    while (m--) {
        int k, d;
        cin >> k >> d;
        auto it = --st.upper_bound(k);
        a[k] -= d;
        if (a[*it] > a[k]) {
            st.emplace(k);
        }
        auto l = st.upper_bound(k);
        auto r = l;
        while (r != st.end() && a[*r] >= a[k]) {
            r++;
        }
        st.erase(l, r);
        cout << st.size() << " ";
    }
    cout << '\n';
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