#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long x = 2; x <= INF; x *= 2) {
        set<long long> st;
        for (int i = 0; i < n; i++) {
            st.emplace(a[i] % x);
        }
        if ((int) st.size() == 2) {
            cout << x << '\n';
            return;
        }
    }
    assert(false);
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