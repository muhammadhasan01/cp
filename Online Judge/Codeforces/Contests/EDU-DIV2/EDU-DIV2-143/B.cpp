#include <bits/stdc++.h>

using namespace std;

const int K = 55;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(K + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l <= k && k <= r) {
            cnt[r + 1]--;
            cnt[l]++;
        }
    }
    for (int i = 1; i <= K; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= K; i++) {
        if (i == k) {
            continue;
        }
        if (cnt[i] == cnt[k]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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