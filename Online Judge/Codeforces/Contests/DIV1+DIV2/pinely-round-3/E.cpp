#include <bits/stdc++.h>

using namespace std;

const int BOUND = 20;

vector<int> pre[BOUND];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cons(m);
    for (auto& [u, v] : cons) {
        cin >> u >> v;
        --u, --v;
    }
    if (n >= BOUND) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
        return;
    }
    for (int buttons : pre[n]) {
        bool valid = true;
        for (auto& [u, v] : cons) {
            if ((buttons & (1 << u)) && !(buttons & (1 << v))) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            continue;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (buttons & (1 << i)) {
                ans.emplace_back(i + 1);
            }
        }
        int k = (int) ans.size();
        cout << k << '\n';
        for (int i = 0; i < k; i++) {
            cout << ans[i] << " \n"[i == k - 1];
        }
        return;
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int n = 1; n < BOUND; n++) {
        int limit = n / 5;
        for (int mask = 1; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) > limit) {
                continue;
            }
            int buttons = 0;
            int cmask = 0;
            for (int i = 0; i < n; i++) {
                if ((cmask & (1 << i)) == (mask & (1 << i))) {
                    continue;
                }
                buttons ^= (1 << i);
                for (int j = i; j < n; j += (i + 1)) {
                    cmask ^= (1 << j);
                }
            }
            pre[n].emplace_back(buttons);
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}