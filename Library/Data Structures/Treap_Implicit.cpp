// https://cp-algorithms.com/data_structures/treap.html

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    int F; // (for function value such as sum/min/max)
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

// l = [0..pos-1], r = [pos..sz]
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
    if (!t) return;
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

// Zero Index
int get_at(pitem t, int pos) {
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    int ret = t2->value;
    merge(t1, t1, t2);
    merge(t, t1, t3);
    return ret;
}

int func(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    int ret = t2->F; // don't forget to change upd() and call it at the end of methods
    merge(t, t1, t2);
    merge(t, t, t3);
    return ret;
}