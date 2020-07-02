#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
string s;
int pre[N][2], suf[N][2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        int n = s.length();
        s = '#' + s;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                pre[i][j] = pre[i - 1][j];
            }
            pre[i][(int) (s[i] - '0')]++;
        }
        suf[n + 1][0] = suf[n + 1][1] = 0;
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 2; j++) {
                suf[i][j] = suf[i + 1][j];
            }
            suf[i][(int) (s[i] - '0')]++;
        }
        int ans = min(n - pre[n][0], n - pre[n][1]);
        for (int i = 1; i < n; i++) {
            ans = min(ans, (i - pre[i][1]) + (n - i - suf[i + 1][0]));
            ans = min(ans, (i - pre[i][0]) + (n - i - suf[i + 1][1]));
        }
        cout << ans << '\n';
    }

    return 0;
}