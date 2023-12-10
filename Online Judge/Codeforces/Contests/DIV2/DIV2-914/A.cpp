#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;
    
    auto getPositions = [&](int x, int y) {
        vector<pair<int, int>> ret;
        for (int di : {1, -1}) {
            for (int dj : {1, -1}) {
                ret.emplace_back(x + a * di, y + b * dj);
                ret.emplace_back(x + b * di, y + a * dj);
            }
        }
        sort(ret.begin(), ret.end());
        ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
        return ret;
    };

    auto k = getPositions(xk, yk);
    auto q = getPositions(xq, yq);
    int ans = 0;
    for (auto kk : k) {
        bool noice = false;
        for (auto qq : q) {
            if (kk == qq) {
                noice = true;
                break;
            }
        }
        if (noice) {
            ++ans;
        }
    }
    cout << ans << '\n';
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