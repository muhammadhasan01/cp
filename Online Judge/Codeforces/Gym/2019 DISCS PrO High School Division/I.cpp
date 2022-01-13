#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int K = 2;
const ll MOD = 1e9 + 7;
struct matrix {
    ll cell[K][K];
    
    matrix() {
        memset(cell, 0, sizeof(cell));
    }

    matrix(vector<vector<ll>> v) {
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                cell[i][j] = v[i][j];
            }
        }
    }
   
    matrix operator*(const matrix& other) const {
        matrix c;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                for (int k = 0; k < K; k++) {
                    c.cell[i][j] = (c.cell[i][j] + cell[i][k] * other.cell[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    matrix fpow(ll b) {
        matrix ret({{1, 0}, {0, 1}});
        matrix a = *this;
        while (b) {
            if (b & 1) ret = (ret * a);
            a = (a * a);
            b >>= 1;
        }
        return ret;
    }
};

ll a, n;

void solve() {
    cin >> a >> n;
    n = abs(n);
    matrix magic({{a % MOD, MOD - 1}, {1, 0}});
    ll t0 = 2;
    ll t1 = (a % MOD);
    if (t1 < 0) t1 += MOD;
    if (n == 0) {
        cout << t0 << '\n';
        return;
    }
    if (n == 1) {
        cout << t1 << '\n';
        return;
    }
    magic = magic.fpow(n - 1);
    ll ans = (magic.cell[0][0] * t1 + magic.cell[0][1] * t0) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}