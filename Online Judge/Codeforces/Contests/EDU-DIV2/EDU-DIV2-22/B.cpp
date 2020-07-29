#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18;

long long x, y, l, r;

void upd(long long& x, long long c) {
    if (x >= INF / c) {
        x = INF;
    } else {
        x = (x * c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> l >> r;
    vector<long long> place;
    place.emplace_back(l - 1);
    place.emplace_back(r + 1);
    long long cur_x = 1;
    for (int i = 0; i <= 60; i++) {
        long long cur_y = 1;
        for (int j = 0; j <= 60; j++) {
            long long val = min(INF, cur_x + cur_y);
            if (val > r) break;
            if (l <= val && val <= r)
                place.emplace_back(val);
            upd(cur_y, y);
            if (cur_y == INF) break;
        }
        upd(cur_x, x);
        if (cur_x == INF) break;
    }
    sort(place.begin(), place.end());
    long long ans = 0;
    for (int i = 0; i < (int) place.size() - 1; i++) {
        ans = max(ans, place[i + 1] - place[i] - 1LL);
    }
    cout << ans << '\n';

    return 0;
}