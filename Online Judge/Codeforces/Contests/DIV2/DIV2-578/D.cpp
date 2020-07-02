#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, k;
char a[N][N];
pair<int,int> p[N][3];
int wl[N][N][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = n + 1, r = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'B') {
                l = min(l, j);
                r = max(l, j);
            }
        }
        if (l == n + 1 && r == 0) {
            r = n + 1;
            res++;
        }
        p[i][0] = {l,r};
    }
    for (int j = 1; j <= n; j++) {
        int l = n + 1, r = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 'B') {
                l = min(l, i);
                r = max(l, i);
            }
        }
        if (l == n + 1 && r == 0) {
            r = n + 1;
            res++;
        }
        p[j][1] = {l,r};
    }
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            if (j == 1) {
                int cur = 0;
                for (int m = j; m <= j + k - 1; m++) {
                    if (p[m][1].first >= i && p[m][1].second <= i + k - 1) cur++;
                }
                wl[i][j][1] = cur;
            } else {
                int cur = wl[i][j - 1][1];
                if (p[j - 1][1].first >= i && p[j - 1][1].second <= i + k - 1) cur--;
                if (p[j + k - 1][1].first >= i && p[j + k - 1][1].second <= i + k - 1) cur++;
                wl[i][j][1] = cur;
            }
        }
    }
    for (int j = 1; j <= n - k + 1; j++) {
        for (int i = 1; i <= n - k + 1; i++) {
            if (i == 1) {
                int cur = 0;
                for (int m = i; m <= i + k - 1; m++) {
                    if (p[m][0].first >= j && p[m][0].second <= j + k - 1) cur++;
                }
                wl[i][j][0] = cur;
            } else {
                int cur = wl[i - 1][j][0];
                if (p[i - 1][0].first >= j && p[i - 1][0].second <= j + k - 1) cur--;
                if (p[i + k - 1][0].first >= j && p[i + k - 1][0].second <= j + k - 1) cur++;
                wl[i][j][0] = cur;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            ans = max(ans, wl[i][j][0] + wl[i][j][1] + res);
        }
    }
    cout << ans << '\n';

    return 0;
}
