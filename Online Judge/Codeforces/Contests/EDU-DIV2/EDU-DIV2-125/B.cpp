#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long B, x, y;
    cin >> n >> B >> x >> y;
    long long cur = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cur + x <= B) {
            cur += x;
        } else {
            cur -= y;
        }
        ans += cur;
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