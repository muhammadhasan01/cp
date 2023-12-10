#include <bits/stdc++.h>

using namespace std;

const int A = 3e3 + 3;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> vals(A);
    int l = A, r = 1;
    for (int i = 1; i <= n; i++) {
        vals[a[i]].emplace_back(i);
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    vector<int> p(n + 1, 1);
    int ans = INT_MAX;
    for (int x = A; x >= 0; x--) {
        bool valid = true;
        while (1) {
            while (vals[r].empty()) {
                --r;
            }
            if (r <= x) {
                break;
            }
            for (int i : vals[r]) {
                p[i] = (a[i] / (a[i] / p[i])) + 1;
                if (p[i] > k) {
                    valid = false;
                    break;
                }
                int nval = a[i] / p[i];
                l = min(l, nval);
                vals[nval].emplace_back(i);
            }
            if (!valid) {
                break;
            }            
            vector<int>().swap(vals[r]);
        }
        if (!valid) {
            break;
        }
        ans = min(ans, x - l);
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