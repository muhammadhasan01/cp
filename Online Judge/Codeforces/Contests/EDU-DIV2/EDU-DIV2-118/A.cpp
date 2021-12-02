#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> x(2);
    vector<int> p(2);
    for (int it = 0; it < 2; it++) {
        cin >> x[it] >> p[it];
    }
    auto get_len = [&](int x) {
        return to_string(x).size();
    };
    vector<int> sz(2);
    for (int it = 0; it < 2; it++) {
        sz[it] = get_len(x[it]) + p[it];
    }
    if (sz[0] > sz[1]) {
        cout << ">" << '\n';
    } else if (sz[0] < sz[1]) {
        cout << "<" << '\n';
    } else if (sz[0] == sz[1]) {
        vector<char> ans = {'>', '<'};
        if (x[0] > x[1]) {
            swap(x[0], x[1]);
            swap(ans[0], ans[1]);
        }
        while (get_len(x[0]) < get_len(x[1])) {
            x[0] = x[0] * 10;
        }
        if (x[0] > x[1]) {
            cout << ans[0] << '\n';
        } else if (x[0] < x[1]) {
            cout << ans[1] << '\n';
        } else if (x[0] == x[1]) {
            cout << "=" << '\n';
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