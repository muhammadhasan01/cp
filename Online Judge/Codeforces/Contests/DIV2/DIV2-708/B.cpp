#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= m;
        cnt[x]++;
    }
    int ans = (cnt[0] > 0);
    for (int rem = 1; rem < m; rem++) {
        int other = m - rem;
        if (rem > other) {
            break;
        }
        int mini = min(cnt[rem], cnt[other]);
        int maxi = max(cnt[rem], cnt[other]);
        if (maxi == 0) {
            continue;
        }
        if (maxi - mini <= 1) {
            ans += 1;
        } else {
            ans += maxi - mini;
        }
    }
    cout << ans << '\n';
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