#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

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

const int INF = 2e9;

int getPos(pitem t, int val) {
    if (!t)
        return -INF;
    if (t->key == val)
        return 1 + cnt(t->l);
    else if (val > t->key)
        return 1 + cnt(t->l) + getPos(t->r, val);
    else
        return getPos(t->l, val);
}

int n, q;
int a[N];
pair<int, int> p[N];
pitem treaps[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    vector<int> values;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        values.emplace_back(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> p[i].first >> p[i].second;
        values.emplace_back(p[i].second);
    }
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());
    for (int i = 1; i <= n; i++) {
        a[i] = upper_bound(values.begin(), values.end(), a[i]) - values.begin();
        pitem new_item = new item(i);
        insert(treaps[a[i]], new_item);
    }
    for (int i = 1; i <= q; i++) {
        p[i].second = upper_bound(values.begin(), values.end(), p[i].second) - values.begin();
        int p1 = p[i].first + 1;
        int p2 = p[i].second;
        erase(treaps[a[p1]], p1);
        pitem new_item = new item(p1);
        insert(treaps[p2], new_item);
        int res = getPos(treaps[p2], p1) - 1;
        if (res <= 0) res = 0;
        cout << res << '\n';
        a[p1] = p2;
    }

    return 0;
}