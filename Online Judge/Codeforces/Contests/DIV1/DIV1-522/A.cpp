#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld a, b, c;
ld x[2], y[2];
pair<ld, ld> p[2];

ld dist(const pair<ld, ld>& a, const pair<ld, ld>& b) {
    ld dx = abs(a.first - b.first); dx *= dx;
    ld dy = abs(a.second - b.second); dy *= dy;
    ld res = dx + dy;
    return sqrtl(res);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);
    cin >> a >> b >> c;
    for (int i = 0; i < 2; i++) {
        cin >> x[i] >> y[i];
    }
    ld ans = llabs(x[1] - x[0]) + llabs(y[1] - y[0]);
    if (x[0] == x[1] || y[0] == y[1]) {
        cout << ans << '\n';
        return 0;
    }
    vector<pair<ld, ld>> v[2];
    for (int i = 0; i < 2; i++) {
        ld _x = x[i];
        ld _y = (-a * _x - c) / b;
        v[i].emplace_back(_x, _y);
        _y = y[i];
        _x = (-b * _y - c) / a;
        v[i].emplace_back(_x, _y);
    }
    for (int i = 0; i < 2; i++)
        p[i] = make_pair(x[i], y[i]);
    for (auto& e1 : v[0]) {
        for (auto& e2 : v[1]) {
            ld cur = dist(p[0], e1) + dist(e1, e2) + dist(e2, p[1]);
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';

    return 0;
}