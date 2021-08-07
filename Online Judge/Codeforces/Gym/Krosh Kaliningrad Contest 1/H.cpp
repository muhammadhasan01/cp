#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5000010;
const int MOD = 1e9+7;
const int S = 4000;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void substract(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

void mult(int &a, int b) {
    a = (1ll * a * b) % MOD;
}

int power(int b, int p) {
    int res = 1;
    while (p) {
        if (p & 1) mult(res, b);
        mult(b, b);
        p /= 2;
    }
    return res;
}

int f[N], f1[N];

void calc() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (1ll * f[i - 1] * i) % MOD;
    for (int i = 0; i < N; i++) f1[i] = power(f[i], MOD - 2);
}

int C(int n, int k) {
    if (n < k) return 0;
    int res = f[n];
    mult(res, f1[k]);
    mult(res, f1[n - k]);
    return res;
}

int G(int n, int m) {
    return C(n - 1, m - 1);
}

int F(int n, int m, int k) { //n up to 50000 * 100 = 5000000, m up to 50000
    int res = G(n, m);
    for (int i = 1; i * k <= n && i <= m; i++) {
        int tmp = G(n - i * k, m);
        mult(tmp, C(m, i));
        if (i & 1) substract(res, tmp);
        else add(res, tmp);
    }
    return res;
}

int n, m, k;
int dp[N + 10];
int p[N + 10];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    if (k > n * m) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    if (k <= S) {
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) p[j] = 0;
            int l = 1, r = m;
            for (int j = 0; j < k; j++) {
                add(p[l], dp[j]);
                if (r < l) add(p[0], dp[j]);
                substract(p[r + 1], dp[j]);
                l++;
                r++;
                if (r == k) r = 0;
            }
            int val = 0;
            for (int j = 0; j < k; j++) {
                add(val, p[j]);
                dp[j] = val;
            }
        }
        ans = dp[0];
    }
    else {
        calc();
        ans = 0;
        for (int sum = k; sum <= n * m; sum += k) {
            add(ans, F(sum, n, m));
        }
    }
    cout << ans << '\n';
    
    return 0;
}