#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    auto get_maks = [&](ll a, ll b, ll n, ll m) -> ll {
        return (n / a) * (m / b);
    };
    auto get_maks_plane = [&](ll a, ll b, ll n, ll m) -> ll {
        ll ret = (n / a) * (m / b);
        ll pa = n % a, pb = m % b;
        if (pa >= b) {
            ret += (pa / b) * (m / a);
        }
        if (pb >= a) {
            ret += (pb / a) * (n / b);
        }
        return ret;
    };
    auto get_maks_sub = [&](ll a, ll b, ll x, ll y, ll z) -> ll {
        vector<ll> v = {x, y, z};
        vector<ll> w = {a, b};
        sort(w.begin(), w.end());
        ll ret = 0;
        do {
            sort(v.begin(), v.end());
            ll a = w[0], b = w[1];
            do {
                ll p = v[0], q = v[1], r = v[2];
                ll cur = get_maks_plane(a, b, p, q) * r;
                ret = max(ret, cur);
            } while (next_permutation(v.begin(), v.end()));
        } while (next_permutation(w.begin(), w.end()));
        return ret;
    };
    vector<ll> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    vector<ll> w(2);
    for (int i = 0; i < 2; i++) {
        cin >> w[i];
    }
    ll n;
    cin >> n;
    sort(w.begin(), w.end());
    ll maks = 0;
    do {
        sort(v.begin(), v.end());
        ll a = w[0], b = w[1];
        do {
            ll p = v[0], q = v[1], r = v[2];
            if (a > p || b > q) {
                continue;
            }
            ll cur = get_maks(a, b, p, q) * r;
            maks = max(maks, cur);
            ll ra = p % a;
            ll rb = q % b;
            if (ra > 0 && rb > 0) {
                ll res = cur + get_maks_sub(a, b, ra, q, r) + get_maks_sub(a, b, p - ra, rb, r);
                maks = max(maks, res);
                res = cur + get_maks_sub(a, b, p, rb, r) + get_maks_sub(a, b, ra, q - rb, r);
                maks = max(maks, res);
            } else if (ra > 0) {
                ll res = cur + get_maks_sub(a, b, ra, q, r);
                maks = max(maks, res);
            } else if (rb > 0) {
                ll res = cur + get_maks_sub(a, b, p, rb, r);
                maks = max(maks, res);
            }
        } while (next_permutation(v.begin(), v.end()));
    } while (next_permutation(w.begin(), w.end()));
    cout << (maks >= n ? "Ya" : "Tidak") << '\n';

    return 0;
}