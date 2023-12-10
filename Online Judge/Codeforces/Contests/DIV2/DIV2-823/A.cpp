#include <bits/stdc++.h>

using namespace std;

const int K = 105;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> cnt(K);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (int x = 1; x < K; x++) {
        ans += min(cnt[x], c);
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