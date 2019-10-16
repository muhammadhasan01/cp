#include<bits/stdc++.h>
using namespace std;

double a[15], b[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double cx1 = 0, cy1 = 0, lx = 105, rx = -105, ly = 105, ry = -105;
    for (int i = 1; i <= 8; i++) {
        cin >> a[i];
        if (i & 1) {
            a[9] += a[i];
            lx = min(lx, a[i]);
            rx = max(rx, a[i]);
        } else {
            a[10] += a[i];
            ly = min(ly, a[i]);
            ry = max(ry, a[i]);
        }
    }
    a[9] /= 4, a[10] /= 4;
    for (int i = 1; i <= 8; i++) {
        cin >> b[i];
        if (i & 1) {
            b[9] += b[i];
        } else {
            b[10] += b[i];
        }
    }
    b[9] /= 4, b[10] /= 4;
    double lxy = 500, rxy = -500, lyx = 500, ryx = -500;
    for (int i = 1; i <= 8; i += 2) {
        double c1 = b[i] + b[i + 1];
        double c2 = b[i + 1] - b[i];
        lxy = min(lxy, c1);
        rxy = max(rxy, c1);
        lyx = min(lyx, c2);
        ryx = max(ryx, c2);
    }
    bool ok = false;
    for (int i = 1; i <= 10; i += 2) {
        if (lx <= b[i] && b[i] <= rx && ly <= b[i + 1] && b[i + 1] <= ry) {
            ok = true;
        }
    }
    for (int i = 1; i <= 10; i += 2) {
        double c1 = a[i] + a[i + 1];
        double c2 = a[i + 1] - a[i];
        if (lxy <= c1 && c1 <= rxy && lyx <= c2 && c2 <= ryx) {
            ok = true;
        }
    }
    puts(ok ? "YES" : "NO");

    return 0;
}
