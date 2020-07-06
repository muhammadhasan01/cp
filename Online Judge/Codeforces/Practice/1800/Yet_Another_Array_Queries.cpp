#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    // long long F; // (for function value such as sum/min/max)
    bool rev;
    pitem l, r;
    item(int value) : prior(rng32()), value(value), cnt(0), rev(false),
                  l(NULL), r(NULL) { }
};

const int N = 2e5 + 5;

int n, q, m;
pitem myTreap;
int ans[N];
int curIdx;

int cnt(pitem it) { return (it ? it->cnt : 0); }

void upd(pitem it) {
    if (!it) return;
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

void getAns(pitem t) {
    if (!t)  return;
    push(t);
    getAns(t->l);
    ans[++curIdx] = t->value;
    getAns(t->r);
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

void erase_at(pitem& t, int pos) {
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    merge(t, t1, t3);
}

int get_at(pitem t, int pos) {
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    int ret = t2->value;
    merge(t1, t1, t2);
    merge(t, t1, t3);
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pitem new_item = new item(x);
        insert(myTreap, i, new_item);
    }
    while (q--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        l--, r--;
        if (tp == 1) {
            int val = get_at(myTreap, r);
            pitem new_item = new item(val);
            erase_at(myTreap, r);
            insert(myTreap, l, new_item);
        } else if (tp == 2) {
            reverse(myTreap, l, r);
        }
    }
    getAns(myTreap);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << ans[x] << (i == m ? '\n' : ' ');
    }

    return 0;
}