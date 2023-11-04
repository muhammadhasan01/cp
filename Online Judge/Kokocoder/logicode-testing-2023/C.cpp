#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int n, m, p;
int sx, sy;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> sx >> sy >> p;
    int dist = INF;
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        x += 1;
        y += 1;
        dist = min(dist, abs(n - x) + abs(m - y));
    }
    sx += 1;
    sy += 1;
    int res = abs(n - sx) + abs(m - sy);
    if (res >= dist) {
        res = -1;
    }
    cout << res << '\n';
    
    return 0;
}