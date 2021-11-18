#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> s(2, vector<char>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    vector<bool> done(n);
    int ans = 0;
    // search for (1, 0) or (0, 1)
    for (int j = 0; j < n; j++) {
        if (s[0][j] != s[1][j]) {
            ans += 2;
            done[j] = true;
        }
    }
    // search for (11, 00) or (00, 11)
    for (int j = 1; j < n; j++) {
        if (done[j] || done[j - 1]) {
            continue;
        }
        if (s[0][j] == s[1][j]) {
            if (s[0][j - 1] == s[1][j - 1]) {
                if (s[0][j] != s[0][j - 1]) {
                    ans += 2;
                    done[j] = done[j - 1] = true;
                }
            }
        }
    }
    // search for (0, 0)
    for (int j = 0; j < n; j++) {
        if (done[j]) {
            continue;
        }
        if (s[0][j] == '0' && s[1][j] == '0') {
            ans++;
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