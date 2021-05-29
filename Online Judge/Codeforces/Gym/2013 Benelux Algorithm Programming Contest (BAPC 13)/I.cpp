#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        mp[b]++;
    }
    long long ans = 1;
    for (auto& [u, v] : mp) {
        ans = (ans * (v + 1));
    }
    cout << ans - 1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}