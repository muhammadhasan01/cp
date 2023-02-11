#include <bits/stdc++.h>

using namespace std;

const int K = 12;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(K);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = K - 1; j >= 0; j--) {
            if (x & (1 << j)) {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
        if (cnt[i] == 0 || cnt[i] == n) {
            continue;
        }
        ans += (1 << i);
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