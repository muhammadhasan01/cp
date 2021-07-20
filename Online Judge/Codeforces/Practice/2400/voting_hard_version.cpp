#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int m, p;
        cin >> m >> p;
        v[m].emplace_back(p);
    }
    int pref = n, cnt = 0;
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = n - 1; i >= 0; i--) {
        pref -= (int) v[i].size();
        for (int x : v[i]) {
            pq.emplace(x);
        }
        int need = i - pref;
        while (cnt < need) {
            int x = pq.top();
            pq.pop();
            ans += x;
            ++cnt;
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