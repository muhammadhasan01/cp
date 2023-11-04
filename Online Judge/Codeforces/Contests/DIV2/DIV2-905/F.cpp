#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> d(n + 2);
    int q;
    cin >> q;
    map<int, long long> mp;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        mp[l] += x;
        mp[r + 1] -= x;
        while (!mp.empty() && mp.begin()->second == 0) {
            mp.erase(mp.begin());
        }
        if (mp.empty() || mp.begin()->second > 0) {
            continue;
        }
        for (auto& [i, val] : mp) {
            d[i] += val;
        }
        mp.clear();
    }
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        long long res = d[i] + a[i];
        cout << res << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}