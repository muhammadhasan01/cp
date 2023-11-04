#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set<long long> st;
    bool isExist = false;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (st.count(k + x) || st.count(x - k)) {
            isExist = true;
        }
        st.emplace(x);
    }
    cout << (isExist ? "YES" : "NO") << '\n';
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