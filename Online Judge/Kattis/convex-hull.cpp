#include <bits/stdc++.h>

using namespace std;

using point = pair<long long, long long>;

int orientation(point p1, point p2, point p3) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    auto [x3, y3] = p3;
    long long val = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
    if (val < 0) {
        return -1;
    }
    if (val > 0) {
        return 1;
    }
    return 0;
}

bool cw(point p1, point p2, point p3) {
    return orientation(p1, p2, p3) < 0;
}

long long distSquare(point p1, point p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<point> p(n);
        for (auto& [x, y] : p) {
            cin >> x >> y;
        }
        point p0 = {INT_MAX, INT_MAX};
        for (auto& [x, y] : p) {
            if (y < p0.second || (y == p0.second && x < p0.first)) {
                p0 = {x, y};
            }
        }
        sort(p.begin(), p.end(), [&](auto& l, auto& r) {
            int o = orientation(p0, l, r);
            if (o == 0) {
                return distSquare(p0, l) < distSquare(p0, r);
            }
            return o < 0;
        });
        vector<point> st;
        for (auto pp : p) {
            while ((int) st.size() >= 2 && !cw(st[(int) st.size() - 2], st.back(), pp)) {
                st.pop_back();
            }
            st.emplace_back(pp);
        }
        if ((int) st.size() == 2 && st[0] == st[1]) {
            st.pop_back();
        }
        reverse(st.begin(), st.end());
        cout << (int) st.size() << '\n';
        for (auto [x, y] : st) {
            cout << x << ' ' << y << '\n';
        }
    }
    
    return 0;
}