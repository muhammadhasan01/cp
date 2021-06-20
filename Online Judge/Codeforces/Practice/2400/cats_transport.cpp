#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int P = 1e2 + 5;

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

int n, m, p;
int d[N];
long long a[M], s[M], dp[M][P];
deque<Line> dq[P];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        int h, t;
        cin >> h >> t;
        a[i] = t - d[h];
        s[i] = a[i] + s[i - 1];
    }
    sort(a + 1, a + 1 + m);
    dq[0].emplace_back(Line(0, 0));
    // dp[i][j] = min{ -a[j] * k + dp[i - 1][k] + s[k] + a[j] * j - s[j] } (k < j)
    // y = mx + c
    // m = -k, c = dp[i - 1][k] + s[k]
    for (int i = 1; i <= m; i++) {
        for (int j = p; j >= 1; j--) {
            if (dq[j - 1].empty()) {
                dp[i][j] = INF;
            } else {
                int sz = dq[j - 1].size();
                while (sz >= 2 && dq[j - 1][0].get(a[i]) >= dq[j - 1][1].get(a[i])) {
                    dq[j - 1].pop_front();
                    sz--;
                }
                dp[i][j] = dq[j - 1][0].get(a[i]) + a[i] * i - s[i];
            }
            int sz = dq[j].size();
            Line cur = Line(-i, dp[i][j] + s[i]);
            while (sz >= 2 && overlap(dq[j][sz - 2], dq[j][sz - 1], cur)) {
                dq[j].pop_back();
                sz--;
            }
            dq[j].emplace_back(cur);
        }
    }
    cout << dp[m][p] << '\n';

    return 0;
}