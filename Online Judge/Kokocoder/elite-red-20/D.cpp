#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<long long> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    set<long long> st;
    long long curSum = 0;
    for (int i = m - 1, k = m; i >= 0; i -= 2, k -= 2) {
        if (d[i] != d[i - 1]) {
            cout << "NO" << '\n';
            return;
        }
        long long val = d[i] - curSum;
        if (val <= 0 || val % k != 0) {
            cout << "NO" << '\n';
            return;
        }
        long long x = val / k;
        if (st.find(x) != st.end()) {
            cout << "NO" << '\n';
            return;
        }
        st.emplace(x);
        curSum += 2LL * x;
    }
    cout << "YES" << '\n';
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