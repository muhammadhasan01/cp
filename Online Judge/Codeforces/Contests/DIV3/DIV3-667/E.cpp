#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        int useless;
        cin >> useless;
    }
    sort(x.begin(), x.end());
    vector<int> res(n), pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin() - 1;
        res[i] = pos[i] - i + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int L = pos[i] - i + 1;
        int R = 0;
        if (pos[i] + 1 < n)
            R = res[pos[i] + 1];
        ans = max(ans, L + R);
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