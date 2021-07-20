#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    // get zeros (a_i == 0)
    vector<int> zeros;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) {
            cout << -1 << '\n';
            return;
        }
        if (a[i] == 0) {
            zeros.emplace_back(i);
        }
    }
    vector<pair<int, int>> ans;
    // handle (a_i > 0 and b_i == 0)
    vector<int> to_zero;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && b[i] == 0) {
            to_zero.emplace_back(i);
        }
    }
    sort(to_zero.begin(), to_zero.end(), [&](int& x, int& y) {
        return a[x] < a[y];
    });
    for (int idx : to_zero) {
        int len = zeros.size();
        if (a[idx] > len) {
            cout << -1 << '\n';
            return;
        }
        for (int j = 0; j < min(len, a[idx]); j++) {
            ans.emplace_back(zeros[j], idx);
        }
        zeros.emplace_back(idx);
        a[idx] = 0;
    }
    // handle (a_i > b_i and b_i > 0)
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i] && b[i] > 0) {
            int len = zeros.size();
            int dif = a[i] - b[i];
            if (dif > len) {
                cout << -1 << '\n';
                return;
            }
            for (int j = 0; j < min(len, dif); j++) {
                ans.emplace_back(zeros[j], i);
            }
            a[i] = b[i];
        }
    }
    // handle (a_i == b_i and b_i > 0)
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] > 0) {
            pos.emplace_back(i);
        }
    }
    for (int idx : pos) {
        for (int x : pos) {
            if (idx == x) {
                continue;
            }
            ans.emplace_back(x, idx);
            if (--a[idx] == 0) {
                break;
            }
        }
        if (a[idx] > 0) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans.size() << '\n';
    for (auto& [u, v] : ans) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("topo.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}