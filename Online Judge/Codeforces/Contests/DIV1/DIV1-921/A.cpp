#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    string cur = "";
    set<char> st;
    for (int i = 0; i < (int) s.length(); i++) {
        st.emplace(s[i]);
        if ((int) st.size() == k) {
            cur += s[i];
            st.clear();
        }
    }
    if ((int) cur.size() >= n) {
        cout << "YES" << '\n';
        return;
    }
    for (char cc = 'a'; cc <= 'z'; cc++) {
        if (st.find(cc) == st.end()) {
            while ((int) cur.size() < n) {
                cur += cc;
            }
            break;
        }
    }
    cout << "NO" << '\n';
    cout << cur << '\n';
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