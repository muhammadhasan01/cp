#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

bitset<MAX> dp;

void solve() {
    long long w, f;
    cin >> w >> f;
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    dp.reset();
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp = (dp | (dp << s[i]));
    }
    long long ans = LLONG_MAX;
    int sum = accumulate(s.begin(), s.end(), 0);
    for (int val = 0; val <= sum; val++) {
        if (dp[val] == 0) {
            continue;
        }
        long long tw = (w + val - 1) / w;
        long long tf = (f + sum - val - 1) / f;
        ans = min(ans, max(tw, tf));
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