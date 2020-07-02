#include <bits/stdc++.h>
using namespace std;

struct st {
    int val, x, y;
};

int tc;
int n, m;
int a[10][105];
st c[10 * 105 + 5];

bool cmpr (st a, st b) {
    if (a.val == b.val) {
        return a.x < b.x;
    }
    return (a.val > b.val);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        int k = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                c[++k].val = a[i][j];
                c[k].x = i, c[k].y = j;
            }
        }
        sort(c + 1, c + 1 + k, cmpr);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += c[i].val;
        }
        if (n == 4 && m > 1) {
            ans = 0;
            for (int i = 1; i <= 5; i++) {
                int cur = 0;
                set<int> col;
                vector<int> cols[105];
                int p1 = -1, p2 = -1;
                for (int j = 1; j <= 5; j++) {
                    if (i == j) continue;
                    cur += c[j].val;
                    if (p1 == -1) p1 = c[j].y;
                    else if (p1 != c[j].y) p2 = c[j].y;
                    col.insert(c[j].y);
                    cols[c[j].y].push_back(c[j].x);
                }
                if ((int) col.size() == 2 && (int) cols[p1].size() == (int) cols[p2].size()) {
                    int d1 = abs(cols[p1][0] - cols[p1][1]);
                    int d2 = abs(cols[p2][0] - cols[p2][1]);
                    if (abs(d1 - d2) & 1) continue;
                }
                ans = max(ans, cur);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
