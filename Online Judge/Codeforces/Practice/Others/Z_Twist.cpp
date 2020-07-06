#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    // int F; (for function value such as sum/min/max)
    bool rev;
    pitem l, r;
    item(int value) : prior(rng32()), value(value), cnt(0), rev(false),
                  l(NULL), r(NULL) { }
};

int cnt(pitem it) {
    return it ? it->cnt : 0;
}

void upd(pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap(it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge(pitem& t, pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r),  t = l;
    else
        merge(r->l, l, r->l),  t = r;
    upd(t);
}

void split(pitem t, pitem& l, pitem& r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push(t);
    int cur_key = add + cnt(t->l); // implicit key
    if(key <= cur_key)
        split(t->l, l, t->l, key, add),  r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd(t);
}

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void output(pitem t) {
    if (!t)  return;
    push(t);
    output(t->l);
    cout << t->value << ' ';
    output(t->r);
}

// Zero Index
void insert(pitem& t, int pos, pitem new_item) {
    if (!t) {
        t = new_item;
        return;
    }
    pitem t1, t2;
    split(t, t1, t2, pos);
    merge(t1, t1, new_item);
    merge(t, t1, t2);
}

void erase(pitem& t, int value) {
    if (t->value == value)
        merge(t, t->l, t->r);
    else
        erase(value < t->value ? t->l : t->r, value);
    upd(t);
}

// Zero Index
void erase_at(pitem& t, int pos) {
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    merge(t, t1, t3);
}

pitem myTreap;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pitem cur_item = new item(i + 1);
        insert(myTreap, i, cur_item);
    }
    int tc, l, r;
    cin >> tc;
    while (tc--) {
        cin >> l >> r;
        l--, r--;
        reverse(myTreap, l, r);
    }
    output(myTreap);
    cout << '\n';

    return 0;
}