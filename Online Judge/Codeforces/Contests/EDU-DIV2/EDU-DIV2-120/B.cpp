#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    string s;
    cin >> s;
    vector<tuple<char, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = make_tuple(s[i], p[i], i);
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto [cc, pp, idx] = v[i];
        ans[idx] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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