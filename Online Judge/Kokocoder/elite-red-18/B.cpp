#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    long long c;
    int d;
    cin >> n >> c >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long>());

    auto can = [&](int k) -> bool {
        int lastOne = -INF;
        long long sum = 0;
        for (int i = 0, j = 0; i < d; i++) {
            if (i - lastOne > k) {
                j = 0;
                sum += a[j];
                lastOne = i;
                continue;
            }
            if (j + 1 < n) {
                j += 1;
                sum += a[j];
                continue;
            }
        }
        return sum >= c;
    };

    int l = 0, r = INF, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    if (at > d) {
        cout << "Infinity" << '\n';
        return;
    }
    if (at == -1) {
        cout << "Impossible" << '\n';
        return;
    }
    cout << at << '\n';
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