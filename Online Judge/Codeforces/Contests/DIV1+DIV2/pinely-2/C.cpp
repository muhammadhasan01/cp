#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> st;
    for (int i = 0; i <= n; i++) {
        st.emplace(i);
    }
    for (int i = 1; i <= n; i++) {
        st.erase(a[i]);
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = *st.begin();
        st.erase(st.begin());
        st.emplace(a[i]);
    }
    b[0] = *st.begin();
    int m = n + 1;
    for (int i = 1; i <= n; i++) {
        int j = i - k + 1;
        j = (j % m + m) % m;
        cout << b[j] << " \n"[i == n];
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