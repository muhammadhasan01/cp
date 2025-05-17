#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto isPal = [&](string& x) -> bool {
        int m = (int) x.length();
        for (int i = 0, j = m - 1; i < j; i++, j--) {
            if (x[i] != x[j]) {
                return false;
            }
        }
        return true;
    };

    set<string> st;
    set<string> st2;
    for (int i = 0; i < n; i++) {
        if (isPal(s[i])) {
            cout << "YES" << '\n';
            return;
        }
        string rev = s[i];
        reverse(rev.begin(), rev.end());
        if (st.find(rev) != st.end()) {
            cout << "YES" << '\n';
            return;
        }
        int len = (int) s[i].size();
        if (len == 2 && st2.find(rev) != st2.end()) {
            cout << "YES" << '\n';
            return;
        }
        if (len == 3) {
            string cur = s[i].substr(1);
            reverse(cur.begin(), cur.end());
            if (st.find(cur) != st.end()) {
                cout << "YES" << '\n';
                return;
            }
        }
        st.emplace(s[i]);
        if (len == 3) {
            st2.emplace(s[i].substr(0, 2));
        }
    }
    cout << "NO" << '\n';
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