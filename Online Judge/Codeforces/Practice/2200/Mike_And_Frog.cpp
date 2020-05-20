#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e18;

long long m;
long long h[2], a[2], x[2], y[2];
long long dist[2], sz[2];
bool cycle[2];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for (int i = 0; i < 2; i++) {
        cin >> h[i] >> a[i];
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < 2; i++) {
        vector<bool> vis(m);
        vector<int> par(m);
        long long cur = h[i];
        vis[cur] = 1;
        for (int j = 0; j < m; j++) {
            long long temp = (x[i] * cur + y[i]) % m;
            if (vis[temp]) {
                long long curval = cur;
                while (1) {
                    sz[i]++;
                    if (curval == a[i]) cycle[i] = 1;
                    if (curval == temp) break;
                    curval = par[curval];
                }
                break;
            } else {
                if (temp == a[i]) {
                    dist[i] = 1 + j;
                }
                vis[temp] = 1;
                par[temp] = cur;
                cur = temp;
            }
        }
    }
    if (dist[0] == 0 || dist[1] == 0) dismiss();
    long long ans = INF;
    if (dist[0] == dist[1]) ans = min(ans, dist[0]);
    if (cycle[0]) {
        if (cycle[1]) {
            int pos = 0, rpos = 1;
            if (dist[1] < dist[0]) swap(pos, rpos);
            for (long long x = 0; x < sz[pos]; x++) {
                long long cur = (dist[rpos] - dist[pos]) + sz[rpos] * x;
                if (cur % sz[pos] == 0) {
                    ans = min(ans, cur + dist[pos]);
                }
            }
        } else {
            if (dist[1] > dist[0] && (dist[1] - dist[0]) % sz[0] == 0) {
                ans = min(ans, dist[1]);
            }
        }
    } else {
        if (cycle[1]) {
            if (dist[0] > dist[1] && (dist[0] - dist[1]) % sz[1] == 0) {
                ans = min(ans, dist[0]);
            }
        } else {
            // we must have dist[0] == dist[1]
        }
    }
    if (ans == INF) dismiss();
    cout << ans << '\n';

    return 0;
}