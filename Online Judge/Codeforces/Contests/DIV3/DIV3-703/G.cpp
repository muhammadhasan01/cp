#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e17;
const int N = 2e5 + 5;

int n, m;
pair<long long, int> p[N];
int min_idx[N];

void solve() {
    cin >> n >> m;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        p[i].first = p[i - 1].first + x;
        p[i].second = i;
    }
    sum = p[n].first;
    sort(p + 1, p + 1 + n, [&](auto& x, auto& y) {
        if (x.first == y.first)
            return x.second < y.second;
        return x.first > y.first;
    });
    for (int i = 1; i <= n; i++) {
        min_idx[i] = p[i].second;
        if (i > 1) min_idx[i] = min(min_idx[i], min_idx[i - 1]);
    }

    auto can = [&](long long x) -> int {
        int l = 1, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[mid].first >= x) {
                l = mid + 1;
                at = min_idx[mid];
            } else {
                r = mid - 1;
            }
        }
        return at;
    };

    auto get = [&](long long x) -> long long {
        if (x > p[1].first && sum <= 0) return 0;
        if (x <= p[1].first) return can(x);
        long long l = 0, r = (INF + sum - 1) / sum;
        long long ret = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1LL;
            long long val = x - mid * sum;
            int pos = can(val);
            if (pos != -1) {
                r = mid - 1;
                ret = mid * n + pos;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    };

    for (int i = 1; i <= m; i++) {
        long long x; cin >> x;
        cout << get(x) - 1 << " \n"[i == m];
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