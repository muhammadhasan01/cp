#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntl = 0, cntr = 0;
    for (char cc : s) {
        if (cc == '(') {
            cntl++;
        } else if (cc == ')') {
            cntr++;
        }
    }
    if (cntl != cntr) {
        cout << -1 << '\n';
        return;
    }

    auto check = [&](string x) -> bool {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] == '(') {
                ++cur;
            } else if (x[i] == ')') {
                --cur;
                if (cur < 0) {
                    return false;
                }
            }
        }
        return cur == 0;
    };

    string rs = s;
    reverse(rs.begin(), rs.end());
    if (check(s) || check(rs)) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << " \n"[i == n - 1];
        }
        return;
    }

    int cur = 0;
    vector<int> rem;
    vector<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            ++cur;
            st.emplace_back(i);
        } else if (s[i] == ')') {
            --cur;
            if (cur < 0) {
                rem.emplace_back(i);
                cur = 0;
            } else {
                st.pop_back();
            }
        }
    }
    vector<bool> vis(n);
    for (int i : rem) {
        vis[i] = true;
    }
    for (int i : st) {
        vis[i] = true;
    }
    set<int> vals;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (vis[i] ? 1 : 2);
        vals.emplace(a[i]);
    }
    cout << (int) vals.size() << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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