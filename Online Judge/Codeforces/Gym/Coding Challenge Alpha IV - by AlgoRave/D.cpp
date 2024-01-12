#include <bits/stdc++.h>

using namespace std;

const int A = 26;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(A);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        int x = cc - 'a';
        cnt[x]++;
    }
    vector<pair<int, int>> dp(A);
    dp[A - 1] = {cnt[A - 1], 0};
    for (int a = A - 2; a >= 0; a--) {
        dp[a] = {cnt[a], 0};
        int mx = -cnt[a];
        for (int j = a + 1; j < A; j++) {
            auto [x, y] = dp[j];
            int curx = cnt[a] + y;
            int cury = x;
            if (cury - curx > mx) {
                mx = cury - curx;
                dp[a] = {curx, cury};
            }
        }
    }
    auto [alice, bob] = dp[0];
    if (alice == bob) {
        cout << "Draw" << '\n';
    } else if (alice > bob) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
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