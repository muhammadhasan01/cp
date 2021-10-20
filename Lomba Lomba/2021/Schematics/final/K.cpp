#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;


const int INF = 2e9;
const ld EPS = 1e-8;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    int F; // for function value such as sum/min/max
    bool rev;
    pitem l, r;
    item(int value): prior(rng32()), value(value), cnt(0), rev(false), l(0), r(0) {}
};

int cnt(pitem it){
    return it ? it -> cnt : 0;
}
void upd(pitem it){
    if (it){
        it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
    }
}
void push(pitem it){
    if (it && it -> rev){
        it -> rev = false;
        swap(it -> l, it -> r);
        if (it -> l) it -> l -> rev ^= 1;
        if (it -> r) it -> r -> rev ^= 1;
    }
}
void merge(pitem& t, pitem l, pitem r){
    push(l);
    push(r);
    if (!l || !r){
        t = l ? l : r;
    } else if (l -> prior > r -> prior){
        merge(l -> r, l -> r, r), t = l;
    } else{
        merge(r -> l, l, r -> l), t = r;
    }
    upd(t);
}
// l = [0..pos - 1], r = [pos..sz]
void split(pitem t, pitem& l, pitem& r, int key, int add = 0){
    if (!t) return void(l = r = 0);
    push(t);
    int cur_key = add + cnt(t -> l); // implicit key
    if (key <= cur_key){
        split(t -> l, l, t -> l, key, add), r = t;
    } else{
        split(t -> r, t -> r, r, key, add + 1 + cnt(t -> l)), l = t;
    }
    upd(t);
}
void reverse(pitem t, int l, int r){
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2 -> rev ^= 1;
    merge(t, t1, t2);
    merge(t, t, t3);
}
void output(pitem t){
    if (!t) return;
    push(t);
    output(t -> l);
    cout << t -> value << ' ';
    output(t -> r);
}

void insert(pitem& t, int pos, pitem new_item){
    if (!t){
        t = new_item;
        return;
    }
    pitem t1, t2;
    split(t, t1, t2, pos);
    merge(t1, t1, new_item);
    merge(t, t1, t2);
}
void erase(pitem& t, int value){
    if (!t) return;
    if (t -> value == value){
        merge(t, t -> l, t -> r);
    } else{
        erase(value < t -> value ? t -> l : t -> r, value);
    }
    upd(t);
}

// Zero Index
void erase_at(pitem& t, int pos){
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    merge(t, t1, t3);
}
// Zero Index
int get_at(pitem t, int pos){
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    int ret = t2 -> value;
    merge(t1, t1, t2);
    merge(t, t1, t3);
    return ret;
}
int func(pitem t, int l, int r){
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    int ret = t2 -> F; // dont forget to change upd() and call it at the end of methods
    merge(t, t1, t2);
    merge(t, t, t3);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(8);
    int n, q;
    cin >> n >> q;
    pitem a = new item(0);
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        pitem new_item = new item(x);
        insert(a, i, new_item);
    }
    // output(a); cerr << '\n';
    auto solve_swap_sub = [&](int l1, int r1, int l2, int r2) {
        pitem tr1, tr2, tr3;
        split(a, tr1, tr2, l2);
        split(tr2, tr2, tr3, r2 - l2 + 1);
        pitem tl1, tl2, tl3;
        split(tr1, tl1, tl2, l1);
        split(tl2, tl2, tl3, r1 - l1 + 1);
        // tl1, tl2, tl3, tr2, tr3
        // tl1, tr2, tl3, tl2, tr3
        merge(a, tl1, tr2);
        merge(a, a, tl3);
        merge(a, a, tl2);
        merge(a, a, tr3);
    };
    for (int tt = 1; tt <= q; tt++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, l, r;
            cin >> x >> l >> r;
            if (x == 1) {
                l += n, r += n;
            }
            reverse(a, l, r);
        } else if (tp == 2) {
            int x, l1, r1, l2, r2;
            cin >> x >> l1 >> r1 >> l2 >> r2;
            if (x == 1) {
                l1 += n, r1 += n;
                l2 += n, r2 += n;
            }
            solve_swap_sub(l1, r1, l2, r2);
        } else if (tp == 3) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1;
            l2 = l1 + n;
            r2 = r1 + n;
            solve_swap_sub(l1, r1, l2, r2);
        } else if (tp == 4) {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            vector<pair<ll, ll>> points(len);
            {
                pitem t1, t2, t3;
                split(a, t1, t2, l);
                split(t2, t2, t3, r - l + 1);
                int id = 0;
                function<void(pitem)> rec = [&](pitem t) {
                    if (!t) {
                        return;
                    }
                    rec(t->l);
                    points[id++].first = t->value;
                    rec(t->r);
                };
                rec(t2);
                merge(a, t1, t2);
                merge(a, a, t3);
            }
            {
                l += n, r += n;
                pitem t1, t2, t3;
                split(a, t1, t2, l);
                split(t2, t2, t3, r - l + 1);
                int id = 0;
                function<void(pitem)> rec = [&](pitem t) {
                    if (!t) {
                        return;
                    }
                    rec(t->l);
                    points[id++].second = t->value;
                    rec(t->r);
                };
                rec(t2);
                merge(a, t1, t2);
                merge(a, a, t3);
            }
            int min_x = INF, max_x = -INF;
            int min_y = INF, max_y = -INF;
            for (int k = 0; k < len; k++) {
                int x, y;
                tie(x, y) = points[k];
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
           auto check = [&](ld mx, ld my) -> ld {
                ld ret = 0;
                for (int i = 0; i < len; i++) {
                    ll x, y;
                    tie(x, y) = points[i];
                    ld dx = abs(mx - x);
                    ld dy = abs(my - y);
                    ld cur = dx * dx + dy * dy;
                    ret = max(ret, cur);
                }
                // cerr << "CHECK: " << mx << " => " << my << " => " << ret << '\n';
                return ret;
            };
            auto ternary_y = [&](ld x) -> ld {
                ld ret = 0;
                ld ly = min_y, ry = max_y;
                while (ry - ly > EPS) {
                    ld py = ly + (ry - ly) / 3.0;
                    ld qy = ry - (ry - ly) / 3.0;
                    if (check(x, py) > check(x, qy)) {
                        ly = py;
                    } else {
                        ry = qy;
                    }
                }
                return check(x, ly);
            };
            ld lx = min_x, rx = max_x;
            while (rx - lx > EPS) {
                ld px = lx + (rx - lx) / 3.0;
                ld qx = rx - (rx - lx) / 3.0;
                if (ternary_y(px) > ternary_y(qx)) {
                    lx = px;
                } else {
                    rx = qx;
                }
            }
            cout << sqrtl(ternary_y(lx)) << '\n';
        }
    }

    return 0;
}