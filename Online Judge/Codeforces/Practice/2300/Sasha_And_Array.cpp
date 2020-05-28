#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

const int N = 1e5 + 5;
const int SZ = 2;
const int M = 1e9 + 7;
const pll TERM = {0, 0};
const matrix ZERO = {{0, 0}, {0, 0}};
const matrix MULP = {{1, 1}, {1, 0}};
const matrix IDENTITY = {{1, 0}, {0, 1}};

int n, q;
int a[N];
pll t[4 * N];
matrix lazy[4 * N];

matrix mul(const matrix& a, const matrix& b) {
    matrix c = ZERO;
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])) % M;
            }
        }
    }
    return c;
}

matrix fast(matrix a, int y) {
    matrix ret = IDENTITY;
    while (y > 0) {
        if (y & 1) ret = mul(ret, a); 
        y >>= 1;
        a = mul(a, a);
    }
    return ret;
}

pll add(const pll& a, const pll& b) {
    return make_pair((a.first + b.first) % M, (a.second + b.second) % M);
}

pll change(const pll& a, const matrix& b) {
    ll x = (b[0][0] * a.first) % M + (b[0][1] * a.second) % M;
    ll y = (b[1][0] * a.first) % M + (b[1][1] * a.second) % M;
    return make_pair(x, y);
}

void build(int v, int s, int e) {
    lazy[v] = IDENTITY;
    if (s == e) {
        matrix temp = fast(MULP, a[s] - 1);
        t[v] = make_pair(temp[0][0], temp[1][0]);
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = add(t[v << 1], t[v << 1 | 1]);
    }
}

void push(int v, int s, int e) {
    if (s == e) return;
    if (lazy[v] == IDENTITY) return;
    t[v << 1] = change(t[v << 1], lazy[v]);
    t[v << 1 | 1] = change(t[v << 1 | 1], lazy[v]);
    lazy[v << 1] = mul(lazy[v << 1], lazy[v]);
    lazy[v << 1 | 1] = mul(lazy[v << 1 | 1], lazy[v]);
    lazy[v] = IDENTITY;
}

void updateRange(int v, int s, int e, int l, int r, const matrix& val) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v] = change(t[v], val);
        lazy[v] = mul(lazy[v], val);
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), val);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = add(t[v << 1], t[v << 1 | 1]);
}

pll get(int v, int s, int e, int l, int r) {
    if (l > r) return TERM;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    pll p1 = get(v << 1, s, mid, l, min(r, mid));
    pll p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return add(p1, p2);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 1) {
            int x;
            cin >> x;
            matrix val = fast(MULP, x);
            updateRange(1, 1, n, l, r, val);
        } else {
            pll result = get(1, 1, n, l, r);
            long long answer = result.first;
            cout << (answer % M + M) % M << '\n';
        }
    }

    return 0;
}