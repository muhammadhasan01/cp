#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    int key, prior, cnt;
    item * l, * r;
    item() { }
    item(int key) : key(key), prior(rng32()), cnt(1), l(NULL), r(NULL) { }
    
};
typedef item * pitem;

int cnt(pitem t) {
    return t ? t->cnt : 0;
}

void upd(pitem t) {
    if (!t) return;
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

// l gets <= key and r gets > key
void split(pitem t, pitem& l, pitem& r, int key) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split(t->l, l, t->l, key),  r = t;
    else
        split(t->r, t->r, r, key),  l = t;
    upd(t);
}

void merge(pitem& t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r),  t = l;
    else
        merge(r->l, l, r->l),  t = r;
    upd(t);
}

// Zero Indexed
void split_at(pitem t, pitem& l, pitem& r, int pos) {
    if (!t) {
        l = r = NULL;
        return;
    }
    int curpos = cnt(t->l);
    if (pos < curpos)
        split_at(t->l, l, t->l, pos), r = t;
    else
        split_at(t->r, t->r, r, pos - curpos - 1), l = t;
    upd(t);
}

void insert(pitem& t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->l, it->r, it->key),  t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
    upd(t);
}

void erase(pitem& t, int key) {
    if (!t) return;
    if (t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
    upd(t);
}

int getPos(pitem t, int val) {
    if (!t)
        return 0;
    if (t->key <= val) {
        return 1 + cnt(t->l) + getPos(t->r, val);
    } else {
        return getPos(t->l, val);
    }
}

template<typename T = pitem>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) {
        n = _n;
        bit.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            bit[i] = new item(0);
        }
    }

    void add(int x, int val) {
        for ( ; x <= n; x += x & -x) {
            pitem new_item = new item(val);
            insert(bit[x], new_item);
        }
    }

    void remove(int x, int val) {
        for ( ; x <= n; x += x & -x) {
            erase(bit[x], val);
        }
    }

    int get(int x, int pos) {
        int ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += getPos(bit[x], pos);
        return ret;
    }

    int query(int l, int r, int pos) {
        return get(r, pos) - get(l - 1, pos);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    BIT<pitem> bit(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    vector<int> b(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        val[i] = pos[a[i]];
    }
    vector<int> id(n + 1);
    for (int i = 1; i <= n; i++) {
        id[i] = p[b[i]];
    }
    auto build = [&]() -> void {
        for (int i = 1; i <= n; i++) {
            bit.add(i, val[i]);
        }
    };
    auto get_query = [&](int la, int ra, int lb, int rb) -> int {
        return bit.query(la, ra, rb) - bit.query(la, ra, lb - 1);
    };
    auto swap_pos = [&](int x, int y) -> void {
        int pos_x = id[x];
        int pos_y = id[y];
        bit.remove(pos_x, x);
        bit.remove(pos_y, y);
        bit.add(pos_x, y);
        bit.add(pos_y, x);
        pos[b[x]] = y;
        pos[b[y]] = x;
        val[pos_x] = y;
        val[pos_y] = x;
        id[x] = pos_y;
        id[y] = pos_x;
        swap(b[x], b[y]);
    };
    build();
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            cout << get_query(la, ra, lb, rb) << '\n';
        } else if (tp == 2) {
            int x, y;
            cin >> x >> y;
            swap_pos(x, y);
        }
    }
    
    return 0;
}