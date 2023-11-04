#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 10;

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> L(m), R(m);
    for (int i = 0; i < m; i++) {
        char cc;
        cin >> cc;
        L[i] = (cc - '0');
    }
    for (int i = 0; i < m; i++) {
        char cc;
        cin >> cc;
        R[i] = (cc - '0');
    }
    vector<set<int>> pos(K);
    int n = s.length();
    for (int i = 1; i <= n; i++) {
        int cur = s[i - 1] - '0';
        pos[cur].emplace(i);
    }
    vector<int> dp(K, -1);
    {
        for (int i = L[0]; i <= R[0]; i++) {
            if (pos[i].empty()) {
                dp[i] = INF;
            } else {
                dp[i] = *pos[i].begin();
            }
        }
    }
    for (int i = 1; i < m; i++) {
        vector<int> ndp(K, -1);
        for (int j = L[i]; j <= R[i]; j++) {
            for (int x = 0; x < K; x++) {
                if (dp[x] == -1) {
                    continue;
                }
                auto it = pos[j].upper_bound(dp[x]);
                if (it == pos[j].end()) {
                    ndp[j] = INF;
                } else {
                    ndp[j] = max(ndp[j], *it);
                }
            }
        }
        ndp.swap(dp);
    }
    int mx = *max_element(dp.begin(), dp.end());
    cout << (mx > n ? "YES" : "NO") << '\n';
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