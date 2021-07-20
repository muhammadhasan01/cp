#include <bits/stdc++.h>

using namespace std;

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

    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<Line> dq;
    dq.emplace_back(Line(0, 0));
    long long f = 0;
    for (int i = 0; i < n; i++) {
        Line cur_line = Line(-2LL * a[i], a[i] * a[i] + f);
        int sz = dq.size();
        while (sz >= 2 && overlap(dq[sz - 2], dq[sz - 1], cur_line)) {
            dq.pop_back();
            --sz;
        }
        dq.emplace_back(cur_line);
        while ((int) dq.size() >= 2 && dq[0].get(a[i]) >= dq[1].get(a[i])) {
            dq.pop_front();
        }
        f = dq.front().get(a[i]) + a[i] * a[i] + c;
    }
    cout << f << '\n';

    return 0;
}