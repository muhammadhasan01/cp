#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int N = 1e5 + 5;
const ld M = 1e18;
int n;
ld p;
ld a[N], b[N];

bool f(ld x) {
    ld sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max(0.0L, a[i] * x - b[i]);
    }
    return (sum <= x * p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    ld sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p) {
        puts("-1");
        return 0;
    }
    ld le = 0, ri = M;
    for (int it = 1; it <= 200; it++) {
        ld mid = (le + ri) / 2.0;
        if (f(mid)) le = mid;
        else ri = mid;
    }
    if (le > M - 100) {
        puts("-1");
        return 0;
    }
    cout << fixed << setprecision(9) << le << '\n';

    return 0;
}
