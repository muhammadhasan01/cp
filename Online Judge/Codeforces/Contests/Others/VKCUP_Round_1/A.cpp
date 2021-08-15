#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d, h;
    cin >> n >> d >> h;
    int o = d - h;
    if (o > h || (d == 1 && n > 2)) {
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int, int>> ans;
    int u = 2;
    for (int it = 0; it < h; it++) {
        ans.emplace_back(u - 1, u);
        u += 1;
    }
    for (int it = 0; it < o; it++) {
        ans.emplace_back(it == 0 ? (d == h ? 2 : 1) : u - 1, u);
        u += 1;
    }
    int rem = n - d - 1;
    for (int it = 0; it < rem; it++) {
        ans.emplace_back(d == h ? 2 : 1, u++);
    }
    for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}