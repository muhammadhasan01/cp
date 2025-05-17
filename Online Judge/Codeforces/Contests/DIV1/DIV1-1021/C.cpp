#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return a * x;
    }
    ll x1, y1;
    ll g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll modinv(ll a, ll m) {
    ll x, y;
    ll g = egcd(a, m, x, y);
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

pair<ll, ll> solve_congruence(ll a, ll c, ll M) {
    ll g = gcd(a, M);
    if (c % g != 0) {
        return {0, -1};
    }
    a /= g;
    c /= g;
    M /= g;
    ll inv = modinv((a % M + M) % M, M);
    ll r = (inv * ((c % M + M) % M)) % M;
    return {r, M};
}

pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll g = gcd(m1, m2);
    if ((r2 - r1) % g != 0) {
        return {0, -1};
    }
    ll m1_g = m1 / g;
    ll m2_g = m2 / g;
    ll rhs = ((r2 - r1) / g) % m2_g;
    if (rhs < 0) {
        rhs += m2_g;
    }
    ll inv = modinv((m1_g % m2_g + m2_g) % m2_g, m2_g);
    ll k = (rhs * inv) % m2_g;
    ll r = r1 + m1 * k;
    ll l = m1 * m2_g;
    r %= l;
    if (r < 0) {
        r += l;
    }
    return {r, l};
}

void solve() {
    ll n, x, y, vx, vy;
    cin >> n >> x >> y >> vx >> vy;
    ll g = gcd(vx, vy);
    vx /= g;
    vy /= g;
    ll M = 2 * n;
    ll best = -1;

    for (int rx_i = 0; rx_i < 2; rx_i++) {
        ll rx = (rx_i ? n : 0);
        for (int ry_i = 0; ry_i < 2; ry_i++) {
            ll ry = (ry_i ? n : 0);

            ll cx = (rx - x) % M;
            if (cx < 0) {
                cx += M;
            }
            pair<ll, ll> solx = solve_congruence(vx % M, cx, M);
            if (solx.second < 0) {
                continue;
            }
            ll r1 = solx.first;
            ll m1 = solx.second;

            ll cy = (ry - y) % M;
            if (cy < 0) {
                cy += M;
            }
            pair<ll, ll> soly = solve_congruence(vy % M, cy, M);
            if (soly.second < 0) {
                continue;
            }
            ll r2 = soly.first;
            ll m2 = soly.second;
            pair<ll, ll> merged = crt(r1, m1, r2, m2);
            if (merged.second < 0) {
                continue;
            }
            ll t0 = merged.first;
            if (t0 == 0) {
                t0 = merged.second;
            }
            if (best < 0 || t0 < best) {
                best = t0;
            }
        }
    }
    // (use 128‐bit to avoid overflow)
__int128 X = x, Y = y, VX = vx, VY = vy, N = n;
__int128 T = t0;

// total crossings of x = k*n  for k integer, 0 < (k*n – x)/(vx) < t0
// = number of integer k with x/VX < k < (x + VX*T)/N
auto count_family = [&]( __int128 numer, __int128 vel, __int128 T ){
    // we solve 0 < (k*N - numer)/vel < T
    // assume vel>0 (if not, flip signs)
    // => numer/N < k < (numer + vel*T)/N
    // so k_min = floor(numer/N)+1, k_max = ceil((numer+vel*T)/N)-1
    __int128 low = numer / N + 1;
    __int128 up  = (numer + vel*T + N - 1) / N - 1;
    return up >= low ? (long long)(up - low + 1) : 0LL;
};

long long bx = count_family(X,     VX, T);
long long by = count_family(Y,     VY, T);
long long bd = count_family(X+Y, VX+VY, T);

long long bounce_count = bx + by + bd;

    cout << bounce_count << "\n";
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}