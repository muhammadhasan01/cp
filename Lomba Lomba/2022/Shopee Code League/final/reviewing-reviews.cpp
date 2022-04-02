// Author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int NN = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll P = 257;

int na, ma;
int nb, mb;

ll mat[N][N];
ll pat[N][N];
ll ppow[NN], ipow[NN];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a) {
    return fpow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ppow[0] = 1;
    ipow[0] = 1;
    {
        ll IP = inv(P);
        for (int i = 1; i < NN; i++) {
            ppow[i] = ppow[i - 1] * P % MOD;
            ipow[i] = ipow[i - 1] * IP % MOD;
        }
    }

    cin >> na >> ma >> nb >> mb;
    for (int i = 1; i <= na; i++) {
        ll cur = 0;
        for (int j = 1; j <= ma; j++) {
            ll a;
            cin >> a;
            a = a * ppow[i - 1 + (j - 1) * mb] % MOD;
            cur = (cur + a) % MOD;
            mat[i][j] = (mat[i - 1][j] + cur) % MOD;
        }
    }
    for (int i = 1; i <= nb; i++) {
        ll cur = 0;
        for (int j = 1; j <= mb; j++) {
            ll a;
            cin >> a;
            a = a * ppow[i - 1 + (j - 1) * mb] % MOD;
            cur = (cur + a) % MOD;
            pat[i][j] = (pat[i - 1][j] + cur) % MOD;
        }
    }
    auto calc = [&](int ra, int ca, int rb, int cb) -> ll {
        return ((mat[rb][cb] - mat[ra - 1][cb] - mat[rb][ca - 1] + mat[ra - 1][ca - 1]) % MOD + MOD) % MOD;
    };
    int ans = 0;
    for (int i = 1; i + nb - 1 <= na; i++) {
        int ii = i + nb - 1;
        for (int j = 1; j + mb - 1 <= ma; j++) {
            int jj = j + mb - 1;
            ll hash = calc(i, j, ii, jj) * ipow[i - 1 + (j - 1) * mb] % MOD;
            if (hash == pat[nb][mb]) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}