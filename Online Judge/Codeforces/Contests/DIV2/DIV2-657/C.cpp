#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
long long n, m;
pair<long long, long long> p[N];
long long suf[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + m);
    if (n == 1) {
        cout << p[m].first << '\n';
        return;
    }
    if (m == 1) {
        cout << p[m].first + (n - 1LL) * p[m].second << '\n';
        return;
    }
    if (n == 2) {
        long long maks = p[m].first + p[m - 1].first;
        for (int i = 1; i <= m; i++) {
            maks = max(maks, p[i].first + p[i].second);
        }
        cout << maks << '\n';
        return;
    }
    suf[m + 1] = 0;
    for (int i = m; i >= 1; i--) {
        suf[i] = suf[i + 1] + p[i].first;
    }
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        long long cur = p[i].first + (n - 1) * p[i].second;
        res = max(res, cur);
        int l = 1, r = m;
        long long at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[mid].first > p[i].second) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) continue;
        at = max(at, m - (n - 1) + 1);
        int cnt = m - at + 1;
        if (at <= i) cur -= p[i].first, cnt--;
        cur = cur + suf[at] - (1LL) * cnt * p[i].second;
        res = max(res, cur);
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}