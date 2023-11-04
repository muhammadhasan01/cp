#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    long long area = 0;
    long long mx_x = 0;
    long long mx_y = 0;
    for (int i = 0; i < n; i++) {
        auto& [x, y] = p[i];
        cin >> x >> y;
        area += x * y;
        mx_x = max(mx_x, x);
        mx_y = max(mx_y, y);
    }
    set<pair<long long, long long>> cand;
    if (area % mx_x == 0) {
        cand.emplace(mx_x, area / mx_x);
    }
    if (area % mx_y == 0) {
        cand.emplace(area / mx_y, mx_y);
    }
    vector<pair<long long, long long>> ans;
    for (auto [sx, sy] : cand) {
        multiset<pair<long long, long long>> stx;
        multiset<pair<long long, long long>> sty;
        for (auto [x, y] : p) {
            stx.emplace(x, y);
            sty.emplace(y, x);
        }
        long long cx = sx, cy = sy;
        bool isValid = true;
        for (int rep = 0; rep < n; rep++) {
            auto itx = prev(stx.end());
            if (cx == itx->first) {
                cy -= itx->second;
                sty.erase(sty.find({itx->second, itx->first}));
                stx.erase(itx);
                continue;
            }
            auto ity = prev(sty.end());
            if (cy == ity->first) {
                cx -= ity->second;
                stx.erase(stx.find({ity->second, ity->first}));
                sty.erase(ity);
                continue;
            }
            isValid = false;
            break;
        }
        if (!isValid) {
            continue;
        }
        ans.emplace_back(sx, sy);
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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