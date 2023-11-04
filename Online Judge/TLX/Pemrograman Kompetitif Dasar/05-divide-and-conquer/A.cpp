#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto getVal = [&](long long x) -> long long {
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            ret += x / a[i];
            if (ret > INF) {
                return ret;
            }
        }
        return ret;
    };

    long long left = LLONG_MAX;
    function<void(long long, long long)> findLeft = [&](long long l, long long r) {
        if (l > r) {
            return;
        }
        long long mid = (l + r) >> 1LL;
        long long res = getVal(mid);
        if (res >= m) {
            if (res == m) {
                left = min(left, mid);
            }
            findLeft(l, mid - 1);
        } else if (res < m) {
            findLeft(mid + 1, r);
        }
    };

    long long right = -LLONG_MAX;
    function<void(long long, long long)> findRight = [&](long long l, long long r) {
        if (l > r) {
            return;
        }
        long long mid = (l + r) >> 1LL;
        long long res = getVal(mid);
        if (res <= m) {
            if (res == m) {
                right = max(right, mid);
            }
            findRight(mid + 1, r);
        } else if (res > m) {
            findRight(l, mid - 1);
        }
    };

    findLeft(1, INF);
    findRight(1, INF);
    if (left > right) {
        cout << 0 << '\n';
        return 0;
    }
    cout << right - left + 1 << '\n';
    
    return 0;
}