// https://cp-algorithms.com/data_structures/treap.html

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

void output(pitem t) {
    if (!t)  return;
    output(t->l);
    cout << t->key << ' ';
    output(t->r);
}

int kth_number(pitem t, int pos) {
    if (!t) return -1;
    int curpos = 1 + cnt(t->l);
    if (curpos == pos)
        return t->key;
    else if (curpos > pos)
        return kth_number(t->l, pos);
    else
        return kth_number(t->r, pos - curpos);
}

int getPos(pitem t, int val) {
    if (!t)
        return -1;
    if (t->key == val)
        return 1 + cnt(t->l);
    else if (val > t->key) {
        int temp = getPos(t->r, val);
        if (temp == -1) return -1;
        return 1 + cnt(t->l) + temp;
    } else {
        return getPos(t->l, val);
    }
}

pitem unite(pitem l, pitem r) {
    if (!l || !r) return l ? l : r;
    if (l->prior < r->prior) swap(l, r);
    pitem lt, rt;
    split(r, lt, rt, l->key);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}

// Building Treap in O(N) (assuming array already sorted)
void heapify (pitem t) {
    if (!t) return;
    pitem max = t;
    if (t->l != NULL && t->l->prior > max->prior)
        max = t->l;
    if (t->r != NULL && t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap (t->prior, max->prior);
        heapify (max);
    }
}

pitem build (int * a, int n) {
    // Construct a treap on values {a[0], a[1], ..., a[n - 1]}
    if (n == 0) return NULL;
    int mid = n / 2;
    pitem t = new item (a[mid], rand());
    t->l = build(a, mid);
    t->r = build(a + mid + 1, n - mid - 1);
    heapify (t);
    upd(t);
    return t;
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