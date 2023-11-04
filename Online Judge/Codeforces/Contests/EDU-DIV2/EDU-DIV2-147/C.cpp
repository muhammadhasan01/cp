#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = INT_MAX;
    for (char x = 'a'; x <= 'z'; x++) {
        int largest = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == x) {
                cnt = 0;
                continue;
            }
            cnt = cnt + 1;
            largest = max(largest, cnt);
        }
        int res = 0;
        while (largest > 0) {
            largest /= 2;
            res++;
        }
        ans = min(ans, res);
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