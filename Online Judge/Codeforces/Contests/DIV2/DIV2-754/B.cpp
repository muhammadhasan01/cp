#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> ans;
    for (int it = 0; it < n; it++) {
        vector<int> v;
        queue<int> q;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == '0') {
                q.emplace(i);
            } else if (a[i] == '1') {
                st.emplace(i);
            }
        }
        while (true) {
            if (q.empty() || st.empty()) {
                break;
            }
            int x = st.top();
            int y = q.front();
            st.pop();
            q.pop();
            if (x >= y) {
                break;
            }
            v.emplace_back(x);
            v.emplace_back(y);
        }
        if (v.empty()) {
            break;
        }
        sort(v.begin(), v.end());
        int len = v.size();
        vector<char> b = a;
        for (int i = 0; i < len; i++) {
            int x = v[i];
            int y = v[len - i - 1];
            a[x] = b[y];
        }
        ans.emplace_back(v);
    }
    int len = ans.size();
    cout << len << '\n';
    for (auto& v : ans) {
        int m = v.size();
        cout << m << " ";
        for (int i = 0; i < m; i++) {
            cout << v[i] + 1 << " \n"[i == m - 1];
        }
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