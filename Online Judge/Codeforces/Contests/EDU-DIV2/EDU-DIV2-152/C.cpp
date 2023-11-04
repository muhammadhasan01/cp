#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<char> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> L(n + 2);
    for (int i = 1, j = 0; i <= n; i++) {
        if (a[i] == '0') {
            j = i;
        } else if (a[i] == '1') {
            L[i] = j;
        }
    }
    vector<int> R(n + 2);
    for (int i = n, j = n + 1; i >= 1; i--) {
        if (a[i] == '0') {
            R[i] = j;
        } else if (a[i] == '1') {
            j = i;
        }
    }
    set<pair<int, int>> st;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (a[l] == '0') {
            l = R[l];
        }
        if (a[r] == '1') {
            r = L[r];
        }
        if (l >= r) {
            st.emplace(-1, -1);
        } else {
            st.emplace(l, r);
        }
    }
    cout << (int) st.size() << '\n';
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