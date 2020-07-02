#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;

int tc;
int n, m;
char a[N][N];
int cnt[N][2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int k = a[i][j] - '0';
                int idone = i + j - 1;
                int idtwo = n + m - idone;
                int id = min(idone, idtwo);
                cnt[id][k]++;
            }
        }
        int ans = 0;
        int len = (n + m - 1);
        for (int i = 0; i <= len / 2; i++) {
            ans += cnt[i][0] + cnt[i][1] - max(cnt[i][0], cnt[i][1]);
        }
        cout << ans << '\n';
    }

    return 0;
}