#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N];
long long b[N];

struct Line  {
    long long m, c;
    Line() {}
    Line(long long _m, long long _c) : m(_m), c(_c) {}

    double intersect(const Line& other) const {
        return (1.0) * (other.c - c) / (m - other.m);
    };

    long long get(long long x) {
        return m * x + c;
    }

    // intersect(p1, p3) <= intersect(p1, p2)
    friend inline bool overlap(const Line &p1, const Line &p2, const Line &p3) {
        return (p3.c - p1.c) * (p1.m - p2.m) <= (p1.m - p3.m) * (p2.c - p1.c);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    deque<Line> dq;
    // dp[i] = a[i] * b[j] + dp[j]
    long long dp = 0;
    dq.emplace_back(Line(b[1], dp));
    for (int i = 1; i <= n; i++) {
        {
            int sz = (int) dq.size();
            while (sz >= 2 && dq[0].get(a[i]) >= dq[1].get(a[i])) {
                dq.pop_front();
                sz--;
            }
        }
        {
            dp = dq[0].get(a[i]);
            Line cur_line = Line(b[i], dp);
            int sz = (int) dq.size();
            while (sz >= 2 && dq[sz - 2].intersect(cur_line) <= dq[sz - 2].intersect(dq[sz - 1])) {
                dq.pop_back();
                sz--;
            }
            dq.emplace_back(cur_line);
        }
    }
    cout << dp << '\n';

    return 0;
}