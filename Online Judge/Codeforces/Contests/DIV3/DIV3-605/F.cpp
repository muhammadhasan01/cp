#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 1e9;

struct st {
    int x, y, h;
};

int dp[N][N][N];
st trk[N][N][N];
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    s = '#' + s;
    t = '#' + t;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < (int) s.size(); i++) {
        for (int j = 0; j < (int) t.size(); j++) {
            for (int k = 1; k <= 200; k++) {
                st pre;
                pre.x = i + (s[i] == '(' ? -1 : 0);
                pre.y = j + (t[j] == '(' ? -1 : 0);
                pre.h = k - 1;
                if (pre.x >= 0 && pre.y >= 0) {
                    if (dp[pre.x][pre.y][pre.h] != inf) {
                        if (dp[pre.x][pre.y][pre.h] + 1 < dp[i][j][k]) {
                            dp[i][j][k] = dp[pre.x][pre.y][pre.h] + 1;
                            trk[i][j][k] = pre;
                        }
                    }
                }
            }
            for (int k = 199; k >= 0; k--) {
                st pre;
                pre.x = i + (s[i] == ')' ? -1 : 0);
                pre.y = j + (t[j] == ')' ? -1 : 0);
                pre.h = k + 1;
                if (pre.x >= 0 && pre.y >= 0) {
                    if (dp[pre.x][pre.y][pre.h] != inf) {
                        if (dp[pre.x][pre.y][pre.h] + 1 < dp[i][j][k]) {
                            dp[i][j][k] = dp[pre.x][pre.y][pre.h] + 1;
                            trk[i][j][k] = pre;
                        }
                    }
                }
            }
        }
    }

    string ans = "";
    st cur = {(int) s.size() - 1, (int) t.size() - 1, 0};
    while (cur.x != 0 || cur.y != 0 || cur.h != 0) {
        st nxt = trk[cur.x][cur.y][cur.h];

        if (cur.h > nxt.h) ans += "(";
        else ans += ")";

        cur = nxt;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}
