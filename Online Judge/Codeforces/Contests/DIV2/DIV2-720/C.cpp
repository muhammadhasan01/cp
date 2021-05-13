#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int tp, int i, int j, int x) {
        cout << "? " << tp << ' ' << i << ' ' << j << ' ' << x << endl;
        int ans;
        cin >> ans;
        return ans;
    };
    vector<pair<int, int>> cands;
    for (int i = 1; i + 1 <= n; i += 2) {
        if (ask(1, i, i + 1, n - 1) >= n - 1)
            cands.emplace_back(i, i + 1);
    }
    if (n % 2 == 1)
        cands.emplace_back(n - 1, n);
    int mx = -1;
    for (auto [a, b] : cands) {
        if (ask(1, a, b, n - 1) == n) {
            mx = b;
            break;
        }
        if (ask(1, b, a, n - 1) == n) {
            mx = a;
            break;
        }
    }
    assert(mx != -1);
    vector<int> res(n + 1);
    res[mx] = n;
    for (int i = 1; i <= n; ++i) {
        if (i != mx) {
            res[i] = ask(2, i, mx, 1);
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << res[i];
        if (i == n)
            cout << endl;
        else
            cout << " ";
    }
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