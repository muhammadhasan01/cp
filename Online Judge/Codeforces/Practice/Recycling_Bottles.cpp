#include <bits/stdc++.h>
using namespace std;
typedef double ld;

const int N = 1e5 + 5;
int n;

struct point{
    ld x, y;
};

point a, b, t, p;
ld pab = 1e18, pa = 1e18, pb = 1e18;

ld dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
    cin >> n;
    cout << fixed << setprecision(15);
    ld sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p.x >> p.y;
        ld dpt = dist(p, t);
        ld k1 = dist(p, a), k2 = dist(p, b);
        ld paa = k1 - dpt, pbb = k2 - dpt;
        pab = min(pab, min(pa + pbb, pb + paa));
        pa = min(pa, paa);
        pb = min(pb, pbb);
        sum += 2 * dpt;
    }
    cout << sum + min(pab, min(pa, pb)) << '\n';

    return 0;
}
