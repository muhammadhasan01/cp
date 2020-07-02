#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 2e2 + 5;

int tc;
int n;
int a[N];
int pre[N][M];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < M; j++) {
                pre[i][j] = pre[i - 1][j];
            }
            pre[i][a[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            ans = max(ans, pre[n][i]);
        }
        for (int i = 1; i <= n; i++) {
            int cur = pre[i][a[i]];
            int l = i + 1, r = n, pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[n][a[i]] - pre[mid - 1][a[i]] >= cur) {
                    l = mid + 1;
                    pos = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (pos == -1) continue;
            int curAns = 0;
            for (int j = 0; j < M; j++) {
                if (j == a[i]) continue;
                curAns = max(curAns, pre[pos - 1][j] - pre[i][j]);
            }
            ans = max(ans, curAns + 2 * cur);
        }
        for (int i = n; i >= 1; i--) {
            int cur = pre[n][a[i]] - pre[i - 1][a[i]];
            int l = 1, r = i - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[mid][a[i]] >= cur) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (pos == -1) continue;
            int curAns = 0;
            for (int j = 0; j < M; j++) {
                if (j == a[i]) continue;
                curAns = max(curAns, pre[i - 1][j] - pre[pos][j]);
            }
            ans = max(ans, curAns + 2 * cur);
        }
        cout << ans << '\n';
    }

    return 0;
}