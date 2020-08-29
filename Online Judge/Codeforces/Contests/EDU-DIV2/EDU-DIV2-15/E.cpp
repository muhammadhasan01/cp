#include <bits/stdc++.h>

using namespace std;

struct st {
    int mini;
    long long sum;
};

st merge(st a, st b) {
    return {min(a.mini, b.mini), a.sum + b.sum};
}

const int INF = 2e9;
const int N = 1e5 + 5;
const int L = 35;

int n;
long long k;
int par[N];
int w[N];
int up[L][N];
st dp[L][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> par[i];
        ++par[i];
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        up[0][i] = par[i];
        dp[0][i] = {x, x};
    }
    for (int i = 1; i < L; i++) {
        for (int u = 1; u <= n; u++) {
            up[i][u] = up[i - 1][up[i - 1][u]];
            dp[i][u] = merge(dp[i - 1][u], dp[i - 1][up[i - 1][u]]);
        }
    }
    long long x = k;
    for (int i = 1; i <= n; i++) {
        st res = {INF, 0};
        k = x; int u = i;
        for (int it = L - 1; it >= 0; it--) {
            long long cur = (1LL << it);
            if (k >= cur) {
                k -= cur;
                res = merge(res, dp[it][u]); 
                u = up[it][u];
            }
        }
        cout << res.sum << ' ' << res.mini << '\n';
    }

    return 0;
}