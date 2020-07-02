#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>, pair<int,int>> pii;

const int N = 2e3 + 5;
int n;
pair<int,int> p[N];
map<pii, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dy = p[j].second - p[i].second;
            int dx = p[j].first - p[i].first;
            if (dx == 0) {
                mp[{{0, 0},{p[i].first, p[i].first}}]++;
            } else {
                int gg = __gcd(abs(dy), abs(dx));
                dy /= gg, dx /= gg;
                int cy = p[i].second * dx - p[i].first * dy;
                int cx = dx;
                int gxy = __gcd(abs(cx), abs(cy));
                cy /= gxy, cx /= gxy;
                if (dy == 0 && dx < 0) {
                    dx = abs(dx);
                } else if (dy < 0 && dx < 0) {
                    dy = abs(dy), dx = abs(dx);
                } else if (dy < 0 && dx > 0) {
                    dy = -dy, dx = -dx;
                }
                if (cy == 0 && cx < 0) {
                    cx = abs(cx);
                } else if (cx < 0 && cy < 0) {
                    cx = abs(cx), cy = abs(cy);
                } else if (cy < 0 && cx > 0) {
                    cy = -cy, cx = -cx;
                }
                mp[{{dy, dx},{cy, cx}}]++;
            }
        }
    }
    long long m = n;
    long long ans = m * (m - 1) * (m - 2) / 6;
    for (auto e : mp) {
        long long cur = e.second;
        long long l = 0, r = 10000, cans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid * (mid - 1) / 2 <= cur) {
                l = mid + 1;
                cans = mid;
            } else {
                r = mid - 1;
            }
        }
        ans -= cans * (cans - 1) * (cans - 2) / 6;
    }

    cout << ans << '\n';

    return 0;
}
