#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int n, m, x, y, a, b;

void dismiss() {
    cout << "Poor Inna and pony!" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> a >> b;
    vector<pair<int, int>> v = {{1, 1}, {1, m}, {n, 1}, {n, m}};
    int ans = INF;
    for (auto& e : v) {
        int p = e.first;
        int q = e.second;
        if (x == p && q == y) {
            cout << 0 << '\n';
            return 0;
        }
        if (p % a != x % a) continue;
        if (q % b != y % b) continue;
        if (y - b < 1 && y + b > m) continue;
        if (x - a < 1 && x + a > n) continue;
        int d1 = abs(p - x) / a;
        int d2 = abs(q - y) / b;
        if (abs(d1 - d2) & 1) continue;
        ans = min(ans, max(d1, d2));
    }
    if (ans == INF) dismiss();
    cout << ans << '\n';

    return 0;
}