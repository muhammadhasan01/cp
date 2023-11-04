#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> lft;
    unordered_map<int, int> rgt;
    for (int i = 1; i <= n; i++) {
        if (lft.count(a[i]) == 0) {
            lft[a[i]] = i;
        }
        rgt[a[i]] = i;
    }
    int mex = 0;
    for (int i = 0; i <= n + 5; i++) {
        if (lft.count(i) == 0) {
            mex = i;
            break;
        }
    }
    if (mex == 0) {
        cout << "YES" << '\n';
        return; 
    }
    if (lft.count(mex + 1) == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] > mex) {
                cout << "YES" << '\n';
                return;
            }
            if (lft[a[i]] == i) {
                continue;
            }
            cout << "YES" << '\n';
            return;
        }
        cout << "NO" << '\n';
        return;
    }
    for (int i = lft[mex + 1]; i <= rgt[mex + 1]; i++) {
        a[i] = mex;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.emplace(a[i]);
    }
    int newMex = 0;
    for (int i = 0; i <= n + 5; i++) {
        if (st.find(i) == st.end()) {
            newMex = i;
            break;
        }
    }
    cout << (newMex == mex + 1 ? "YES" : "NO") << '\n'; 
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