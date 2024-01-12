#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<long long>>;

matrix I = {{1, 0}, {0, 1}};

matrix mul(const matrix& a, const matrix& b, long long mod) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    matrix ret(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                long long cur = (a[i][k] % mod) * (b[k][j] % mod);
                cur = (cur % mod + mod) % mod;
                ret[i][j] = (ret[i][j] + cur) % mod;
                ret[i][j] = (ret[i][j] % mod + mod) % mod;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b, m;
    cin >> a >> b >> m;
    long long one = ((a % m) + m) % m;
    long long two = (((a * a - 2) % m) + m) % m;
    if (b == 1) {
        cout << one << '\n';
        return 0;
    }
    if (b == 2) {
        cout << two << '\n';
        return 0;
    }

    auto modpow = [&](matrix x, long long k) -> matrix {
        matrix ret = I;
        while (k > 0) {
            if (k & 1) {
                ret = mul(ret, x, m);
            }
            k >>= 1;
            x = mul(x, x, m);
        }
        return ret;
    };

    matrix base = {{one, m - 1}, {1, 0}};
    matrix M = modpow(base, b - 2);
    long long res = (M[0][0] * two) % m;
    res += (M[0][1] * one) % m;
    cout << (res % m + m) % m << '\n';
    
    return 0;
}