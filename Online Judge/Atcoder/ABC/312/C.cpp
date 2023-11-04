#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto can = [&](int x) -> bool {
        int L = upper_bound(a.begin(), a.end(), x) - a.begin();
        int R = m - (lower_bound(b.begin(), b.end(), x) - b.begin());
        return L >= R;
    };

    int l = 0, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}