#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pos(k + 1);
    for (int i = 0; i < n; i++) {
        pos[a[i]].emplace_back(i);
    }
    vector<int> L(k + 1, n + 1), R(k + 1, -1);
    int val = k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = make_pair(a[i], i);
    }
    sort(p.rbegin(), p.rend());
    int mostLeft = n + 1, mostRight = -1;
    for (auto [x, i] : p) {
        while (val >= x) {
            for (int j : pos[val]) {
                mostLeft = min(mostLeft, j);
                mostRight = max(mostRight, j);
            }
            --val;
        }
        if (mostLeft > mostRight) {
            continue;
        }
        L[x] = min(L[x], mostLeft);
        R[x] = max(R[x], mostRight);
    }
    for (int x = 1; x <= k; x++) {
        int res = 0;
        if (L[x] <= R[x]) {
            res += 2 * (R[x] - L[x] + 1);
        }
        cout << res << " \n"[x == k];
    }
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