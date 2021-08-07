#include <bits/stdc++.h>

using namespace std;
 
const int N = 400010;
const int INF = 1000000000;
const int MOD = 1e9+7;
 
int len[N];
int n, x, k;
int a[N];
 
int power(int b, int p) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = (1ll * res * b) % MOD;
        }
        b = (1ll * b * b) % MOD;
        p /= 2;
    }
    return res;
}
 
 
int getAnswer() {
    int ans = 0;
    if (x == 1) {
        return 1;
    }
    if (k == 0) {
        ans = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i + 1]) ans++;
        }
    }
    else {
        int twopower = power(2, k - 1);
        int xrev = power(x, MOD - 2);
        int prob1 = (1ll * (x - 2) * xrev) % MOD;
        int prob2 = (1ll * (x - 1) * xrev) % MOD;
        ans = (1ll * twopower * n) % MOD;
        ans = (MOD + ans - twopower) % MOD;
        ans = (ans + 1) % MOD;
        ans = (ans * 2) % MOD;
        ans = (1ll * ans * prob2) % MOD;
        ans = (MOD + ans - prob1) % MOD;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << getAnswer() << endl;
    
    return 0;
}