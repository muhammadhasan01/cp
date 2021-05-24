#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        if (i > 0 && v[i - 1] != v[i]) {
            flag = true;
        }
        if (i + 1 < n && v[i + 1] != v[i]) {
            flag = true;
        }
        if (flag) ++ans;
    }
    cout << ans << "\n";
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