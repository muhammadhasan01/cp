#include <bits/stdc++.h>

using namespace std;

const int K = 3;
const int dx[] = {-1, 0, 1};

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<bool> dp(3, true);
    for (int i = 1; i < n; i++) {
        vector<bool> ndp(3, false);
        for (int j = 0; j < K; j++) {
            int cur = x[i] + dx[j];
            for (int k = 0; k < K; k++) {
                int bef = x[i - 1] + dx[k];
                if (bef + 1 == cur && dp[k]) {
                    ndp[j] = true;
                }
            }
        }
        dp.swap(ndp);
    }
    if (dp[0] || dp[1] || dp[2]) {
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << '\n';
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