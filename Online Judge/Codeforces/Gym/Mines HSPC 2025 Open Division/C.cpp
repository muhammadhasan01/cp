#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct st {
    ll num, den;
    int type;
    st(ll num_, ll den_, int type_) : num(num_), den(den_), type(type_) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<st> events;
    for (int i = 0; i < n; ++i) {
        ll x, a, b;
        cin >> x >> a >> b;
        events.push_back(st(a, x, 1));
        events.push_back(st(b, x, -1));
    }
    sort(events.begin(), events.end(), [&](auto &e1, auto &e2) {
        ll lhs = 1LL * e1.num * e2.den;
        ll rhs = 1LL * e2.num * e1.den;
        if (lhs != rhs)
            return lhs < rhs;
        return e1.type > e2.type;
    });
    int cnt = 0, ans = 0;
    for (const auto &e : events) {
        cnt += e.type;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    
    return 0;
}