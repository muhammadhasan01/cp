// https://cp-algorithms.com/data_structures/treap.html

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    // int F; (for function value such as sum/min/max)
    bool rev;
    pitem l, r;
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
    printf("%d ", t->value);
    output(t->r);
}

void insert(pitem& t, pitem new_item) {
    pitem t1, t2;
    split(t, t1, t2, new_item->key) // new_item->key = pos
    merge(t, t, new_item);
    merge(t, t1, t2);
}

void erase(pitem& t, int key) {
    if (t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
    upd(t);
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