#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> vals(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vals[a].emplace_back(b);
    }
    long long ans = 0;
    for (int a = 1; a <= n; a++) {
        sort(vals[a].rbegin(), vals[a].rend());
        int len = (int) vals[a].size();
        for (int rep = 0; rep < min(len, a); rep++) {
            ans += vals[a][rep];
        }
    }
    cout << ans << '\n';
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