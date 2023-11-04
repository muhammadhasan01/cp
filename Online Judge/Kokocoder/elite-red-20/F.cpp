#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e12;

int n, m;
long long h[N], p[N];

long long getz(long long x, long long y, long long z) {
    return min((y - x) * 2 + (z - y), (y - x) + (z - y) * 2);
}

bool can(long long x) {
    long long cur = min(p[1], h[1]);
    if (h[1] - cur > x) return false;
    int idx = 1;
    int iter = 1;
    while (iter <= m) {
        if (p[iter] > h[idx]) {
            if (getz(cur, h[idx], p[iter]) > x) {
                if (++idx > n) return false;
                cur = min(p[iter], h[idx]);
                if (h[idx] - cur > x) return false;
            } else {
                iter++;
            }
        } else if (p[iter] <= h[idx]) {
            iter++;
        }
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    long long l = 0, r = INF, ans = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
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