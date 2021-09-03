#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<deque<int>> cnt(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 2].emplace_back(i);
    }
    int par = 0;
    if ((int) cnt[1].size() > (int) cnt[0].size()) {
        par = 1;
    }
    int len = cnt[par].size();
    if (len > (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    auto check = [&](int x) -> int {
        int ret = 0;
        for (int i = 0, j = 0; i < n; i += 2) {
            ret += abs(i - cnt[x][j++]);
        }
        return ret;
    };
    int ans = check(par);
    if (n % 2 == 0) {
        ans = min(ans, check(1 - par));
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