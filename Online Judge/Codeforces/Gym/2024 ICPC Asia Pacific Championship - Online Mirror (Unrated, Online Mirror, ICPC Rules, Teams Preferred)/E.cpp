#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    auto check = [&]() -> bool {
        for (int i = 1; i <= n; i++) {
            vector<int> cnt(n + 1);
            bool ok = false;
            for (int j = 1; j <= n; j++) {
                if (++cnt[a[i][j]] > 1) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }
        for (int j = 1; j <= n; j++) {
            vector<int> cnt(n + 1);
            bool ok = false;
            for (int i = 1; i <= n; i++) {
                if (++cnt[a[i][j]] > 1) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }
        return true;
    };

    vector<int> V;
    for (int i = 1; i <= n; i++) {
        vector<int> cnt(n + 1);
        bool ok = false;
        for (int j = 1; j <= n; j++) {
            if (++cnt[a[i][j]] > 1) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            V.emplace_back(i);
        }
    }
    vector<int> H;
    for (int j = 1; j <= n; j++) {
        vector<int> cnt(n + 1);
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            if (++cnt[a[i][j]] > 1) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            H.emplace_back(j);
        }
    }
    if (H.empty() && V.empty()) {
        cout << 0 << '\n';
        return;
    }
    if (H.empty()) {
        H.emplace_back(1);
    }
    if (V.empty()) {
        V.emplace_back(1);
    }
    vector<pair<int, int>> pos;
    int hlen = (int) H.size();
    int vlen = (int) V.size();
    for (int i = 0, j = 0; i < vlen || j < hlen; ) {
        pos.emplace_back(V[i], H[j]);
        if (i == vlen - 1 && j + 1 < hlen) {
            j++;
        } else if (j == hlen - 1 && i + 1 < vlen) {
            i++;
        } else {
            i++;
            j++;
        }
    }
    vector<vector<int>> original = a;
    for (int val = 1; val <= n; val++) {
        for (auto [i, j] : pos) {
            int x = val;
            if (original[i][j] == val) {
                x = (val == 1 ? n : 1);
            }
            a[i][j] = x;
        }
        if (check()) {
            cout << (int) pos.size() << '\n';
            for (auto [i, j] : pos) {
                cout << i << ' ' << j << ' ' << a[i][j] << '\n';
            }
            return;
        }
    }
    assert(false);
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