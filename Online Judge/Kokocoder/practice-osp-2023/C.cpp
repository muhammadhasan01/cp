#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    auto can = [&](int dist) -> bool {
        int cnt = 1;
        int lst = 0;
        for (int i = 1; i < n; i++) {
            if (x[i] - x[lst] >= dist) {
                cnt++;
                lst = i;
            }
            if (cnt >= c) {
                return true;
            }
        }
        return cnt >= c;
    };

    int l = 1, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
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