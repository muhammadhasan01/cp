#include <bits/stdc++.h>

using namespace std;

const int K = 30;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(K + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = K; j >= 0; j--) {
            bool b = x & (1 << j);
            if (b) {
                cnt[j]++;
            }
        }
    }
    int res = 0;
    for (int j = K; j >= 0; j--) {
        if (cnt[j] + k >= n) {
            int add = min(n - cnt[j], k);
            k -= add;
            cnt[j] += add;
        }
        if (cnt[j] == n) {
            res += (1 << j);
        }
    }
    cout << res << '\n';
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