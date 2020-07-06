#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 500;

struct item {
    int val, prior, cnt; 
    int maxi, mini, mdif;
    item *l, *r;
    item(int val) : val(val), prior(rand()), cnt(0), maxi(-INF), mini(INF), mdif(INF),
                    l(NULL), r(NULL) { }
};
typedef item* pitem;

int cnt(pitem t) { return (t ? t->cnt : 0); }
int maxi(pitem t) { return (t ? t->maxi : -INF); }
int mini(pitem t) { return (t ? t->mini : INF); }
int mdif(pitem t) { return (t ? t->mdif : INF); }

void upd(pitem t) {
    if (!t) return;
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
    t->mini = min(t->val, min(mini(t->l), mini(t->r)));
    t->maxi = max(t->val, max(maxi(t->l), maxi(t->r)));
    t->mdif = INF;
    if (t->l)
        t->mdif = min(t->mdif, min(t->val - maxi(t->l), mdif(t->l)));
    if (t->r)
        t->mdif = min(t->mdif, min(mini(t->r) - t->val, mdif(t->r)));
}

void split(pitem t, pitem& l, pitem& r, int val) {
    if (!t)
        l = r = NULL;
    else if (val < t->val)
        split(t->l, l, t->l, val),  r = t;
    else
        split(t->r, t->r, r, val),  l = t;
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

void insert(pitem& t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->l, it->r, it->val),  t = it;
    else
        insert(it->val < t->val ? t->l : t->r, it);
    upd(t);
}

void erase(pitem& t, int val) {
    if (!t) return;
    if (t->val == val)
        merge(t, t->l, t->r);
    else
        erase(val < t->val ? t->l : t->r, val);
    upd(t);
}

void insert_val(pitem& t, int val) {
    pitem it = new item(val), L, R;
    split(t, t, R, val);
    split(R, L, R, val + 1);
    merge(t, t, R);
    insert(t, it);
}

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

int query(pitem t, int l, int r, bool maks) {
    if (l >= r) return -1;
    pitem L1, L2, L3;
    split_at(t, L1, L2, l - 1);
    split_at(L2, L2, L3, r - l);
    int ret = (maks ? maxi(L2) - mini(L2) : mdif(L2));
    merge(t, L1, L2);
    merge(t, t, L3);
    return (ret >= INF ? -1 : ret);
}

pitem myTreap;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    srand(time(NULL));
    int tc, val, l, r;
    char tp;
    cin >> tc;
    while (tc--) {
        cin >> tp;
        if (tp == 'I') {
            cin >> val;
            insert_val(myTreap, val);
        } else if (tp == 'D') {
            cin >> val;
            erase(myTreap, val);
        } else if (tp == 'N') {
            cin >> l >> r;
            cout << query(myTreap, l, r, 0) << '\n';
        } else if (tp == 'X') {
            cin >> l >> r;
            cout << query(myTreap, l, r, 1) << '\n';
        }
    }

    return 0;
}