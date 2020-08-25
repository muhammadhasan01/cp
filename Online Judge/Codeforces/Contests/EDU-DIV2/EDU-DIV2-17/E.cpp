#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int F = 1e4 + 5;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

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

int get(pitem t, int val) {
    if (!t) return 0;
    if (val < t->key)
        return get(t->l, val);
    else
        return 1 + cnt(t->l) + get(t->r, val);
}

struct radio {
    int x, r, f;
    bool operator<(const radio& other) const {
        return (r < other.r);
    };
};

int n, k;
pitem treaps[F];
radio rad[N];

int main() {
    inpos(n), inpos(k);
    for (int i = 1; i <= n ; i++) {
        inpos(rad[i].x), inpos(rad[i].r), inpos(rad[i].f);
        pitem new_item = new item(rad[i].x);
        insert(treaps[rad[i].f], new_item);
    }
    sort(rad + 1, rad + 1 + n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = max(1, rad[i].f - k); j <= min(F - 5, rad[i].f + k); j++) {
            int R = get(treaps[j], (1LL) * rad[i].x + rad[i].r);
            int L = get(treaps[j], (1LL) * rad[i].x - rad[i].r - 1);
            ans += (1LL) * (R - L);
        }
        erase(treaps[rad[i].f], rad[i].x);
    }
    outpos(ans - n);
    return 0;
}   