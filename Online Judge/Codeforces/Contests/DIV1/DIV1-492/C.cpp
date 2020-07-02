#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1e5 + 5;
const ll Max = 2250000000000;
const ll INF = 1e18;

struct st {
    int idx;
    ll x, y;
    bool operator<(const st& other) {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

int n;
st p[N];
ll curx, cury;
int ans[N];

ll F(ll x, ll y) {
    return x * x + y * y;
}

ll check(ll idx, ll sign) {
    ll tempx = curx + sign * p[idx].x;
    ll tempy = cury + sign * p[idx].y;
    return F(tempx, tempy);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    sort(p + 1, p + 1 + n);
    int l = 1, r = n;
    while (l <= r) {
        ll res = INF;
        vector<pll> v = {{l, 1}, {l, -1}, {r, 1}, {r, -1}};
        pll pos;
        for (auto e : v) {
            ll curval = check(e.first, e.second);
            if (res > curval) {
                res = curval;
                pos = e;
            }
        }
        curx = curx + pos.second * p[pos.first].x;
        cury = cury + pos.second * p[pos.first].y;
        ans[p[pos.first].idx] = pos.second;
        if (pos.first == l) l++;
        else r--;
    }
    // assert(F(curx, cury) <= Max);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}