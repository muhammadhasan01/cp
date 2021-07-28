#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[(i - a[i] + n) % n]++;
    }
    vector<int> ans;
    for (int k = 0; k < n; k++) {
        if (cnt[k] + 2 * m >= n) {
            vector<int> p(n);
            for (int i = 0; i < n; i++) {
                p[(i - k + n) % n] = a[i];
            }
            int cyc = 0;
            vector<bool> vis(n);
            for (int i = 0; i < n; i++) {
                if (vis[i]) {
                    continue;
                }
                int j = i;
                while (!vis[j]) {
                    vis[j] = true;
                    j = p[j];
                }
                cyc++;
            }
            if (n - cyc <= m) {
                ans.emplace_back(k);
            }
        }
    }
    cout << ans.size();
    for (int k : ans) {
        cout << " " << k;
    }
    cout << "\n";
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}