#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    int pos = max_element(p.begin() + 1, p.end()) - p.begin();

    auto getPerm = [&](int l, int r) -> vector<int> {
        vector<int> ret(n);
        int idx = 0;
        for (int i = r + 1; i < n; i++) {
            ret[idx++] = p[i];
        }
        for (int i = r; i >= l; i--) {
            ret[idx++] = p[i];
        }
        for (int i = 0; i < l; i++) {
            ret[idx++] = p[i];
        }
        return ret;
    };

    vector<vector<int>> ans;
    ans.emplace_back(getPerm(pos, pos));
    ans.emplace_back(getPerm(0, pos));
    for (int r = pos - 1, l = pos - 1; l >= 0; l--) {
        ans.emplace_back(getPerm(l, r));
    }
    sort(ans.begin(), ans.end());
    vector<int> res = ans.back();
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
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