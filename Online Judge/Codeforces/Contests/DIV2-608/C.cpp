#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;
int n, sx, sy, c;
pair<int, int> p[N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans, px, py;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> sx >> sy;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < 4; i++) {
        int cx = sx + dx[i];
        int cy = sy + dy[i];
        if (cx < 0 || cx > INF) continue;
        if (cy < 0 || cy > INF) continue;
        int cur = 0;
        for (int j = 1; j <= n; j++) {
            if (cx < sx) {
                if (p[j].first <= cx) {
                    cur++;
                }
            } else if (cx > sx) {
                if (p[j].first >= cx) {
                    cur++;
                }
            } else if (cy > sy) {
                if (p[j].second >= cy) {
                    cur++;
                }
            } else if (cy < sy) {
                if (p[j].second <= cy) {
                    cur++;
                }
            }
        }
        if (ans < cur) {
            ans = cur;
            px = cx, py = cy;
        }
    }
    cout << ans << '\n';
    cout << px << " " << py << '\n';

    return 0;
}
