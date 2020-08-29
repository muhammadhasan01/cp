#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 100;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    vector<int> tow(m);
    for (int i = 0; i < m; i++) {
        cin >> tow[i];
    }
    sort(pos.begin(), pos.end());
    sort(tow.begin(), tow.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tow.begin(), tow.end(), pos[i]);
        int res = INF;
        if (it != tow.end()) {
            res = min(res, *it - pos[i]);
        }
        if (it != tow.begin()) {
            --it;
            res = min(res, pos[i] - *it);
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';

    return 0;
}