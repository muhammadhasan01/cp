#include <bits/stdc++.h>

using namespace std;
using Line = tuple<int, int, long long>;
using Point = pair<int, int>;

struct Info {
    Line l;
    Point p;
    int c;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }
    vector<Info> v;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int g = __gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            if (dx == 0 && dy < 0) {
                dy = -dy;
            }
            int mx = x[i] + x[j];
            int my = y[i] + y[j];
            long long val = 1LL * dx * mx + 1LL * dy * my;
            Line l = make_tuple(dx, dy, val);
            Point p = make_pair(mx, my);
            v.emplace_back(Info{l, p, c[i] + c[j]});
        }
    }
    sort(v.begin(), v.end(), [&](auto& lhs, auto& rhs) {
        if (lhs.l != rhs.l) {
            return lhs.l < rhs.l;
        }
        if (lhs.p != rhs.p) {
            return lhs.p < rhs.p;
        }
        return lhs.c > rhs.c;
    });
    long long ans = -1;
    int len = (int) v.size();
    for (int i = 0; i < len; i++) {
        int j = i;
        while (j + 1 < len && v[i].l == v[j + 1].l) {
            j++;
        }
        pair<int, int> best = make_pair(v[i].c, -1);
        for (int k = i + 1; k <= j; k++) {
            if (v[k].p == v[k - 1].p) {
                continue;
            }
            if (v[k].c >= best.first) {
                best.second = best.first;
                best.first = v[k].c;
            } else if (v[k].c > best.second) {
                best.second = v[k].c;
            }
        }
        if (best.second != -1) {
            ans = max(ans, 1LL * best.first + best.second);
        }
        i = j;
    }
    cout << ans << '\n';
    
    return 0;
}