#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e9 + 7;
int p[2] = {31,37};
int n;
long long c[N][2], pre[N][2];
string res = "";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0][0] = pre[0][1] = 1;
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= N - 5; i++) {
            pre[i][t] = pre[i - 1][t] * p[t];
            pre[i][t] %= M;
        }
    }

    cin >> n;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        string r;
        cin >> r;
        if (i == 1) {
            res = r;
            for (int t = 0; t < 2; t++) {
                for (int i = len; i < res.size(); i++) {
                    c[i][t] = (i > 0) * c[i - 1][t] + (1LL) * (res[i] - '0') * pre[i][t];
                    c[i][t] %= M;
                }
            }
            len = res.size();
        } else {
            int rlen = r.size();
            vector<vector<bool>> vis(2, vector<bool>(rlen + 3, 0));
            for (int t = 0; t < 2; t++) {
                long long cur = 0;
                for (int i = 0; i < min(rlen, len); i++) {
                    cur += (1LL) * (r[i] - '0') * pre[i][t];
                    cur %= M;
                    long long ccur = (c[len - 1][t] - (len - i - 2 < 0 ? 0 : c[len - i - 2][t]));
                    ccur = (ccur % M + M) % M;
                    long long rcur = cur * pre[len - i - 1][t];
                    rcur = (rcur % M + M) % M;
                    if (rcur == ccur) vis[t][i] = 1;
                }
            }
            int reslen = -1;
            for (int i = min(rlen, len) - 1; i >= 0; i--) {
                if (vis[0][i] && vis[1][i]) {
                    reslen = i;
                    break;
                }
            }
            res += r.substr(reslen + 1);
            for (int t = 0; t < 2; t++) {
                for (int i = len; i < res.size(); i++) {
                    c[i][t] = (i > 0) * c[i - 1][t] + (1LL) * (res[i] - '0') * pre[i][t];
                    c[i][t] %= M;
                }
            }
            len = res.size();
        }
    }
    cout << res << '\n';

    return 0;
}
