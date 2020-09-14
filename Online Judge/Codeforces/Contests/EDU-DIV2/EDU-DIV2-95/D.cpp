#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/** END OF TEMPLATE DEBUGGER **/

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct item {
    int val, prior, cnt; 
    int maxi, mini, mdif;
    item *l, *r;
    item(int val) : val(val), prior(rng32()), cnt(0), maxi(-INF), mini(INF), mdif(INF),
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
    t->mdif = 0;
    if (t->l)
        t->mdif = max(t->mdif, max(t->val - maxi(t->l), mdif(t->l)));
    if (t->r)
        t->mdif = max(t->mdif, max(mini(t->r) - t->val, mdif(t->r)));
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

int kth_number(pitem t, int pos) {
    if (!t) return -1;
    int curpos = 1 + cnt(t->l);
    if (curpos == pos)
        return t->val;
    else if (curpos > pos)
        return kth_number(t->l, pos);
    else
        return kth_number(t->r, pos - curpos);
}

int n, q;
pitem treap;

void answer() {
    if (n <= 1) {
        cout << 0 << '\n';
        return;
    }
    int firstEl = kth_number(treap, 1);
    int lastEl = kth_number(treap, n);
    debug() << imie(n) imie(firstEl) imie(lastEl);
    int ans = (lastEl - firstEl) - query(treap, 0, n - 1, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pitem new_item = new item(x);
        insert(treap, new_item);
    }
    answer();
    while (q--) {
        int tp, x;
        cin >> tp >> x;
        if (tp) {
            ++n;
            pitem new_item = new item(x);
            insert(treap, new_item);
        } else {
            --n;
            erase(treap, x);
        }
        answer();
    }

    return 0;
}