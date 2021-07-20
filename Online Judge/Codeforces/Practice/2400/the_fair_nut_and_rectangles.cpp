#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

struct Line  {
    long long m, c;
    Line() {}
    Line(long long _m, long long _c) : m(_m), c(_c) {}

    long double intersectX(const Line& other) const {
        return (long double) (other.c - c) / (m - other.m);
    };

    long long get(long long x) {
        return m * x + c;
    }

    // intersectX(p1, p3) <= intersectX(p1, p2)
    friend inline bool overlap(const Line &p1, const Line &p2, const Line &p3) {
        return (p3.c - p1.c) * (p1.m - p2.m) <= (p1.m - p3.m) * (p2.c - p1.c);
    }
};

int n;
tuple<int, int, long long> p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; long long a;
        cin >> x >> y >> a;
        p[i] = make_tuple(x, y, a);
    }
    sort(p + 1, p + 1 + n);
    // dp[i] = -x[j] * y[i] + dp[j] + x[i] * y[i] - a[i]
    // y = mx + c
    // m = -x[j], c = dp[j]
    deque<Line> dq;
    long long dp = 0;
    long long ans = 0;
    dq.emplace_back(Line(0, dp));
    for (int i = 1; i <= n; i++) {
        auto [x, y, a] = p[i];
        {
            int sz = dq.size();
            while (sz >= 2 && dq[0].get(y) <= dq[1].get(y)) {
                dq.pop_front();
                sz--;
            }
            dp = dq[0].get(y) + 1LL * x * y - a;
        }
        ans = max(ans, dp);
        {
            Line cur_line = Line(-x, dp);
            int sz = dq.size();
            while (sz >= 2 && dq[sz - 2].intersectX(cur_line) >= dq[sz - 2].intersectX(dq[sz - 1])) {
                dq.pop_back();
                sz--;
            }
            dq.emplace_back(cur_line);
        }
    }
    cout << ans << '\n';

    return 0;
}