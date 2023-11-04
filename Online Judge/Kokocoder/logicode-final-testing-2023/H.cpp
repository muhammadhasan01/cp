#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    long long ans = 0;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        if (last != -1) {
            ans += 1LL * last;
        }
        if (i + 1 <= n && v[i] > v[i + 1]) {
            last = i;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}