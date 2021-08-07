#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 300010;
const int MOD = 1e9+7;
const int B = 30;

int n, a[N];
int lpos[N], rpos[N];
int s[40][N], cnt[40][N];

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int product(int a, int b) {
    return (1ll * a * b) % MOD;
}

int getcnt(int b, int l, int r, int val) {
    int res = cnt[b][r];
    if (l != 0) res -= cnt[b][l - 1];
    if (val == 0) res = r - l + 1 - res;
    return res;
}

int stup() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int mx = -1, xr = 0;
        for (int j = i; j <= n; j++) {
            mx = max(mx, a[j]);
            xr ^= a[j];
            int tmp= (1ll * mx * xr) % MOD;
            ans = (ans + tmp) % MOD;
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 2e9;
    a[n + 1] = 2e9;
    for (int i = 1; i <= n; i++) {
        lpos[i] = i - 1;
        while (a[lpos[i]] < a[i]) lpos[i] = lpos[lpos[i]];
    }
    for (int i = n; i >= 1; i--) {
        rpos[i] = i + 1;
        while (a[rpos[i]] <= a[i]) rpos[i] = rpos[rpos[i]];
    }
    for (int b = 0; b < B; b++) {
        s[b][0] = 0;
        for (int i = 1; i <= n; i++) {
            s[b][i] = s[b][i - 1];
            if (a[i] & (1 << b)) s[b][i] ^= 1;
        }
        cnt[b][0] = 0;
        for (int i = 1; i <= n; i++) {
            cnt[b][i] = cnt[b][i - 1] + s[b][i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = lpos[i] + 1, r = rpos[i] - 1;
        for (int b = 0; b < B; b++) {
            int segs = 0;
            add(segs, product(getcnt(b, i, r, 1), getcnt(b, l - 1, i - 1, 0)));
            add(segs, product(getcnt(b, i, r, 0), getcnt(b, l - 1, i - 1, 1)));
            int tmp = product(segs, (1 << b));
            add(ans, product(tmp, a[i]));
        }
    }
    cout << ans << '\n';

    return 0;
}