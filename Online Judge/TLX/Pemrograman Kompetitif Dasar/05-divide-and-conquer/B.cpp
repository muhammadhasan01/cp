#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6;

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
    
    int a, b;
    cin >> a >> b;
    bool isExceed = false;
    long long cur = 1;
    for (int rep = 1; rep <= b; rep++) {
        cur = (cur * a);
        if (cur >= MOD) {
            isExceed = true;
            break;
        }
    }
    string res = to_string(fastpow(a, b));
    if (isExceed) {
        while ((int) res.size() < 6) {
            res = "0" + res;
        }
    }
    cout << res << '\n';
    
    return 0;
}