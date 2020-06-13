/**
F(k, a, b) = a * fib[k - 2] + b * fib[k - 1]
S(k, a, b) = F(k + 2, a, b) - F(2, a, b)
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 3e5 + 5;
const ll M = 1e9 + 9;
const pll ZERO = {0LL, 0LL};

int n, m;
ll a[N];
ll fib[N];
ll t[4 * N];
pll lazy[4 * N];

ll FIB(ll k, pll x) {
    ll a = x.first;
    ll b = x.second;
    assert(k > 0);
    if (k == 1) return a % M;
    if (k == 2) return b % M;
    return (a * fib[k - 2] + b * fib[k - 1]) % M;
}

ll S(ll k, pll x) {
    ll ret = ((FIB(k + 2, x) - FIB(2, x)) % M + M) % M;
    return ret;
}

void add(pll& a, pll b) {
    a.first = (a.first + b.first) % M;
    a.second = (a.second + b.second) % M;
}

void upd(ll& a, ll k, pll x) {
    a = (a + S(k, x)) % M;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = (t[v << 1] + t[v << 1 | 1]) % M;
}

void push(int v, int s, int e) {
    if (s == e) return;
    if (lazy[v] == ZERO) return;

    int mid = (s + e) >> 1;
    add(lazy[v << 1], lazy[v]);
    upd(t[v << 1], mid - s + 1, lazy[v]);

    int pos = ((mid + 1) - s + 1);
    pll cur = make_pair(FIB(pos, lazy[v]), FIB(pos + 1, lazy[v]));
    
    add(lazy[v << 1 | 1], cur);
    upd(t[v << 1 | 1], e - mid, cur);

    lazy[v] = ZERO;
}

void updateRange(int v, int s, int e, int l, int r, int pos) {
    if (l > r) return;
    if (l == s && e == r) {
        pll cur = make_pair(fib[s - pos + 1], fib[s - pos + 2]);
        add(lazy[v], cur);
        upd(t[v], e - s + 1, cur);
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), pos);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, pos);
    t[v] = (t[v << 1] + t[v << 1 | 1]) % M;
}

ll get(int v, int s, int e, int l, int r) {
    if (l > r) return 0LL;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    ll p1 = get(v << 1, s, mid, l, min(r, mid));
    ll p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return (p1 + p2) % M;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fib[1] = 1;
    for (int i = 2; i < N; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % M;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 1) { 
            updateRange(1, 1, n, l, r, l);
        } else if (tp == 2) {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}