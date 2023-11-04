#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> mini(n);
    for (int l = 0, r = 0; l < n; l++) {
        while (b[r] < a[l]) {
            r++;
        }
        mini[l] = b[r] - a[l];
    }
    vector<int> maxi(n);
    set<int> st;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > b[i - 1]) {
            st.emplace(i - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        auto it = st.lower_bound(i);
        int rgt = (it != st.end() ? *it : n - 1);
        maxi[i] = b[rgt] - a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << mini[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << maxi[i] << " \n"[i == n - 1];
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