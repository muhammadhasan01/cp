#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e2 + 5;
const int T = 15;

int n, q, c;
vector<pair<int, int>> vx[M];
vector<int> pre[M][T];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        vx[x].emplace_back(y, s);
    }
    for (int i = 1; i < M; i++) {
        sort(vx[i].begin(), vx[i].end());
        int len = vx[i].size();
        for (int it = 0; it <= c; it++) {
            pre[i][it].assign(len, 0);
            for (int j = 0; j < len; j++) {
                if (j > 0) pre[i][it][j] = pre[i][it][j - 1];
                pre[i][it][j] += (vx[i][j].second + it) % (c + 1);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int t, xl, yl, xu, yu;
        cin >> t >> xl >> yl >> xu >> yu;
        t %= (c + 1);
        int ans = 0;
        for (int x = xl; x <= xu; x++) {
            int lenz = vx[x].size();
            int l = 0, r = lenz - 1, posl = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (vx[x][mid].first >= yl) {
                    r = mid - 1;
                    posl = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (posl == -1) continue;
            if (vx[x][posl].first > yu) continue;
            l = 0, r = lenz - 1;
            int posu = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (vx[x][mid].first <= yu) {
                    l = mid + 1;
                    posu = mid; 
                } else {
                    r = mid - 1;
                }
            }
            int right = pre[x][t][posu];
            int left = (posl == 0 ? 0 : pre[x][t][posl - 1]);
            int curval = right - left;
            ans += curval;
        }
        cout << ans << '\n';
    }

    return 0;
}