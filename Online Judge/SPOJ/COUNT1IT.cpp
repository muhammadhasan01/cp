#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    long long key, prior, cnt;
    item * l, * r;
    item() { }
    item(long long key) : key(key), prior(rng32()), cnt(1), l(NULL), r(NULL) { }
    
};
typedef item * pitem;

long long cnt(pitem t) {
    return t ? t->cnt : 0;
}

void upd(pitem t) {
    if (!t) return;
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

// l gets <= key and r gets > key
void split(pitem t, pitem& l, pitem& r, long long key) {
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
void split_at(pitem t, pitem& l, pitem& r, long long pos) {
    if (!t) {
        l = r = NULL;
        return;
    }
    long long curpos = cnt(t->l);
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

void erase(pitem& t, long long key) {
    if (!t) return;
    if (t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
    upd(t);
}

long long smaller_or_equal(pitem t, long long x) {
    pitem it;
    split(t, t, it, x);
    long long ret = cnt(t);
    merge(t, t, it);
    return ret;
}

long long kth_number(pitem t, long long pos) {
    if (!t) return -1;
    long long curpos = 1 + cnt(t->l);
    if (curpos == pos)
        return t->key;
    else if (curpos > pos)
        return kth_number(t->l, pos);
    else
        return kth_number(t->r, pos - curpos);
}

void output(pitem t) {
    if (!t)  return;
    output(t->l);
    cout << t->key << ' ';
    output(t->r);
}

int n, q;
int tp;
long long x;
pitem myTreap;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (long long i = 0; i < n; i++) {
        cin >> x;
        pitem new_item = new item(x);
        insert(myTreap, new_item);
    }
    while (q--) {
        cin >> tp >> x;
        if (tp == 1) {
            long long val = x + smaller_or_equal(myTreap, x);
            pitem new_item = new item(val);
            insert(myTreap, new_item);
        } else if (tp == 2) {
            cout << smaller_or_equal(myTreap, x) << '\n';
        } else if (tp == 3) {
            int res = kth_number(myTreap, x);
            if (res == -1)
                cout << "invalid" << '\n';
            else
                cout << res << '\n';
        }
    }

    return 0;
}