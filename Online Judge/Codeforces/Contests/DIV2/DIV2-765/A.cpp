#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> cnt0(l + 1), cnt1(l + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j <= l; j++) {
            if (x & (1 << j)) {
                cnt1[j]++;
            } else {
                cnt0[j]++;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= l; j++) {
        ans += (cnt1[j] > cnt0[j] ? (1 << j) : 0);
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