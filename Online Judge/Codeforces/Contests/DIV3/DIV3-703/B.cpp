#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x % 3]++;
    }
    int ans = 0;
    int m = n / 3;
    for (int it = 0; it < 5; it++) {
        for (int i = 0; i < 3; i++) {
            if (v[i] > m) {
                ans += v[i] - m;
                v[(i + 1) % 3] += v[i] - m;
                v[i] = m;
            }
        }
    }
    cout << ans << '\n';
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