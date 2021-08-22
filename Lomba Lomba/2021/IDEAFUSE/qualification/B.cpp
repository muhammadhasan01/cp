#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    map<string, int> occ;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        set<string> st;
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            if (st.find(s) == st.end()) {
                st.emplace(s);
                mp[s] += 1;
            }
            occ[s] += 1;
        }
    }
    vector<tuple<int, int, string>> v;
    for (auto& e : mp) {
        v.emplace_back(-e.second, -occ[e.first], e.first);
    }
    sort(v.begin(), v.end());
    int len = min(5, (int) v.size());
    for (int i = 0; i < len; i++) {
        cout << get<2>(v[i]) << " \n"[i == len - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case #" << T << ": ";
        solve();
    }
    
    return 0;
}