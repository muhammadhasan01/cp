#include <bits/stdc++.h>

using namespace std;

int MOD;

int fastpow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        int res = fastpow(a, b / 2);
        return (1LL * res * res) % MOD;
    }
    return (1LL * a * fastpow(a, b - 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c >> MOD;
    int res = a;
    for (int rep = 1; rep <= c; rep++) {
        res = fastpow(res, b);
    }
    cout << res + 1 << '\n';
    
    return 0;
}