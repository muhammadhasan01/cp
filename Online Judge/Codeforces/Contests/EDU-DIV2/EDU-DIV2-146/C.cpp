#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        r[i] = make_pair(x, i + 1);
    }
    sort(r.rbegin(), r.rend());
    vector<int> v1, v2;
    int c1 = 0, c2 = 0;
    for (auto [val, pos] : r) {
        if (1LL * (c1 + 1) * s1 < 1LL * (c2 + 1) * s2) {
            c1++;
            v1.emplace_back(pos);
        } else {
            c2++;
            v2.emplace_back(pos);
        }
    }
    for (auto v : {v1, v2}) {
        cout << v.size() << " ";
        for (int x : v) {
            cout << x << " ";
        }
        cout << '\n';
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