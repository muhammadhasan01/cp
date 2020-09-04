#include <bits/stdc++.h>

using namespace std;

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

struct vertex {
    int val;
    vertex *l, *r;
    vertex(int val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(0), l(l), r(r) {
        if (l) val += l->val;
        if (r) val += r->val;
    }
};
typedef vertex* pvertex;

struct range {
    int l, r, idx;
    bool operator<(const range& other) {
        return l < other.l;
    };
};

const int N = 2e5 + 5;

int n;
range a[N];
pvertex psegtree[N];
int ans[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(0);
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos) {
    if (s == e && s == pos)
        return new vertex(1);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos));
}

int getQuery(pvertex v, pvertex w, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return v->val - w->val;
    int mid = (s + e) >> 1;
    int p1 = getQuery(v->l, w->l, s, mid, l, r);
    int p2 = getQuery(v->r, w->r, mid + 1, e, l, r);
    return p1 + p2;
}

int main() { 
    inpos(n);
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        int l, r; inpos(l), inpos(r); 
        nums.emplace_back(l); nums.emplace_back(r);
        a[i].l = l, a[i].r = r;
        a[i].idx = i;
    }
    sort(nums.begin(), nums.end());
    sort(a + 1, a + 1 + n);
    auto getIdx = [&](int x) {
        int pos = lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
        return pos;
    };
    int len = nums.size();
    psegtree[0] = build(1, len);
    for (int i = 1; i <= n; i++) {
        a[i].l = getIdx(a[i].l); a[i].r = getIdx(a[i].r);
        psegtree[i] = update(psegtree[i - 1], 1, len, a[i].r);
    }
    for (int i = 1; i < n; i++) {
        if (a[i + 1].l > a[i].r) continue;
        int l = i + 1, r = n, pos = i + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid].l < a[i].r) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int res = getQuery(psegtree[pos], psegtree[i], 1, len, 1, a[i].r - 1);
        ans[a[i].idx] = res;
    }
    for (int i = 1; i <= n; i++) {
        outpos(ans[i]);
    }
    return 0;
}