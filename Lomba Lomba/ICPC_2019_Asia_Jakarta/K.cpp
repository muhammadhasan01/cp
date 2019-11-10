// source : https://codeforces.com/blog/entry/70757?#comment-554191
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

typedef long long ll;

ll MOD = 1e9 + 7;

struct node {
    ll x1, y1, x2, y2;
    bool lazy;
    node(ll x1 = 1, ll y1 = 0, ll x2 = 0, ll y2 = 1) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        lazy = false;
    }
};

node t[N << 2];
char s[N];
int n, q;

void apply(node &a, node b, node c) {
    a.x1 = (b.x1 * c.x1 + b.y1 * c.x2) % MOD;
    a.y1 = (b.x1 * c.y1 + b.y1 * c.y2) % MOD;
    a.x2 = (b.x2 * c.x1 + b.y2 * c.x2) % MOD;
    a.y2 = (b.x2 * c.y1 + b.y2 * c.y2) % MOD;
}

void build(int k, int l, int r){
    if (l == r) {
        if (s[l] == 'A') {
            t[k].x1 = t[k].y1 = t[k].y2 = 1;
            t[k].x2 = 0;
        } else {
            t[k].x1 = t[k].x2 = t[k].y2 = 1;
            t[k].y1 = 0;
        }
        return;
    }
    int m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 ^ 1, m + 1, r);
    apply(t[k], t[k << 1 ^ 1], t[k << 1]);
}

void lazy(int k, int l, int r) {
    if (t[k].lazy) {
        swap(t[k].x1, t[k].y2);
        swap(t[k].x2, t[k].y1);
        if (l < r) {
            t[k << 1].lazy ^= 1;
            t[k << 1 ^ 1].lazy ^= 1;
        }
        t[k].lazy = false;
    }
}

void update(int k, int l, int r, int x, int y) {
    lazy(k, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        t[k].lazy ^= 1;
        lazy(k, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(k << 1, l, m, x, y);
    update(k << 1 ^ 1, m + 1, r, x, y);
    apply(t[k], t[k << 1 ^ 1], t[k << 1]);
}

node get(int k, int l, int r, int x, int y) {
    lazy(k, l, r);
    if (l > y || r < x) return node();
    if (l >= x && r <= y) return t[k];
    int m = (l + r) >> 1;
    node t1 = get(k << 1, l, m, x, y);
    node t2 = get(k << 1 ^ 1, m + 1, r, x, y);
    node t0;
    apply(t0, t2, t1);
    return t0;
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    cin >> n >> q;
    cin >> s + 1;
    build(1, 1, n);
    while (q--) {
        int id, l, r;
        cin >> id >> l >> r;
        if (id == 1) {
            update(1, 1, n, l, r);
        } else {
            ll a, b;
            cin >> a >> b;
            node t0 = get(1, 1, n, l, r);
            ll A = (t0.x1 * a + t0.y1 * b) % MOD;
            ll B = (t0.x2 * a + t0.y2 * b) % MOD;
            cout << A << " " << B << endl;
        }
    }
}
