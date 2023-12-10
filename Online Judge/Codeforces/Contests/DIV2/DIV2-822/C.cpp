#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> mn(n + 1, INF);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] == '1') {
                break;
            }
            mn[j] = min(mn[j], i);
        }
        if (mn[i] != INF) {
            ans += mn[i];
        }
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