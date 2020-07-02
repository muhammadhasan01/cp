#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld r, x11, y11, x2, y2;
ld x3, y3, r3;

ld dist(ld a, ld b, ld c, ld d) {
    return (a - c) * (a - c) + (b - d) * (b - d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> x11 >> y11 >> x2 >> y2;
    cout << fixed << setprecision(15);
    if ((x11 - x2) * (x11 - x2) + (y11 - y2) * (y11 - y2) >= r * r) {
        cout << x11 << " " << y11 << " " << r << '\n';
        return 0;
    }
    if (x11 == x2) {
        x3 = x11;
        y3 = (y11 + y2 + (y11 >= y2 ? r : -r)) / 2;
        r3 = abs(y3 - y2);
        cout << x3 << " " << y3 << " " << r3 << '\n';
    } else {
        ld grad = (y2 - y11) / (x2 - x11);
        ld c = y11 - grad * x11;
        ld ak = (1 + grad * grad);
        ld bk = -2 * x11 + 2 * grad * (c - y11);
        ld ck = x11 * x11 + (c - y11) * (c - y11) - r * r;
        ld ax11 = (-bk + sqrt(bk * bk - 4 * ak * ck)) / (2 * ak);
        ld ay11 = grad * ax11 + c;
        ld ax2 = (-bk - sqrt(bk * bk - 4 * ak * ck)) / (2 * ak);
        ld ay2 = grad * ax2 + c;
        if (dist(x2, y2, ax11, ay11) > dist(x2, y2, ax2, ay2)) {
            cout << (x2 + ax11) / 2 << " " << (y2 + ay11) / 2 << " " << sqrt(dist(x2, y2, ax11, ay11)) / 2 << '\n';
        } else {
            cout << (x2 + ax2) / 2 << " " << (y2 + ay2) / 2 << " " << sqrt(dist(x2, y2, ax2, ay2)) / 2 << '\n';
        }
    }

    return 0;
}
