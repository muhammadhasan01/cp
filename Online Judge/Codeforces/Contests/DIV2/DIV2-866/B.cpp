#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    bool isOne = true;
    for (char cc : s) {
        if (cc == '0') {
            isOne = false;
        }
    }
    if (isOne) {
        cout << 1LL * n * n << '\n';
        return;
    }
    string p = s + s;
    int m = p.length();
    vector<int> last(m, -1);
    for (int i = 0; i < m; i++) {
        if (p[i] == '0') {
            last[i] = i;
        } else if (i > 0) {
            last[i] = last[i - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (p[i] == '0') {
            continue;
        }
        int len = min(n, i - last[i]) + 1;
        int take = len / 2;
        long long res = 1LL * take * (len - take);
        ans = max(ans, res); 
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