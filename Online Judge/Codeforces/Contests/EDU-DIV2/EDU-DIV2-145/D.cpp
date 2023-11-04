#include <bits/stdc++.h>

using namespace std;

const long long X = 1e12;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> pref(n, vector<int>(2));
    vector<vector<int>> suff(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            for (int j = 0; j < 2; j++) {
                pref[i][j] = pref[i - 1][j];
            }
        }
        int num = s[i] - '0';
        pref[i][num]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) {
            for (int j = 0; j < 2; j++) {
                suff[i][j] = suff[i + 1][j];
            }
        }
        int num = s[i] - '0';
        suff[i][num]++;
    }
    long long ans = 1LL * min(pref[n - 1][0], pref[n - 1][1]) * (X + 1);
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        if (i - 1 >= 0) {
            cur += (X + 1) * pref[i - 1][1];
        }
        if (i + 1 < n) {
            cur += (X + 1) * suff[i + 1][0];
        }
        ans = min(ans, cur);
    }
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '1' && s[i] == '0') {
            long long cur = X;
            if (i - 2 >= 0) {
                cur += (X + 1) * pref[i - 2][1];
            }
            if (i + 1 < n) {
                cur += (X + 1) * suff[i + 1][0];
            }
            ans = min(ans, cur);
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