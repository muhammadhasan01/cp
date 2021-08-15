#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 2e5 + 5;
const int K = 3;

int n, m;
char s[N];
int pre[N][K][K];

void solve() {
    cin >> n >> m;
    for (int j = 0; j < K; j++) {
        for (int k = 0; k < K; k++) {
            pre[0][j][k] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int num = s[i] - 'a';
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < K; k++) {
                if (i > 0) {
                    pre[i][j][k] = pre[i - 1][j][k];
                }
            }
        }
        pre[i][i % K][num]++;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        vector<int> v(3);
        iota(v.begin(), v.end(), 0);
        int ans = INF;
        do {
            int res = r - l + 1;
            for (int i = 0; i < K; i++) {
                int pos = l + i;
                int at = pos % K;
                if (pos > r) {
                    break;
                }
                int cur = pre[r][at][v[i]];
                if (pos > 0) {
                    cur -= pre[pos - 1][at][v[i]];
                }
                res -= cur;
            }
            ans = min(ans, res);
        } while (next_permutation(v.begin(), v.end()));
        cout << ans << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}