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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 1e5 + 5;
const long long INF = 1e16;
const long long TERM = -INF;

int n, q;
long long a[N];
long long dif = 0;

struct SegtreeLazy {
    vector<long long> t;
    vector<long long> lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0LL);
        lazy.assign(4 * N, 0LL);
    }

    long long combine(const long long& x, const long long& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0LL || s == e) return;
        t[v << 1] += lazy[v];
        t[v << 1 | 1] += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, long long val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    long long get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        long long p1 = get(v << 1, s, mid, l, min(r, mid));
        long long p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} sgt;

void change(long long x, long long y) {
    if (x <= 0 && y <= 0)
        return;
    else if (x <= 0 && y > 0)
        dif += y;
    else if (x > 0 && y <= 0)
        dif -= x;
    else if (x > 0 && y > 0)
        dif += (y - x);
}

long long F(long long x, long long y) {
    long long ret = max(x + dif, y - x);
    return ret;
}

void answer() {
    long long one = sgt.get(1, 1, n, 1, 1);
    long long ans = max(dif + (one - dif) / 2LL, one - (one - dif) / 2LL);
    debug(one, dif, ans);
    outpos(ans);
}

int main() {
    inpos(n);
    for (int i = 1; i <= n; i++) {
        inpos(a[i]);
        if (i > 1) dif += max(0LL, a[i] - a[i - 1]);
    }
    sgt.build(1, 1, n);
    answer();
    inpos(q);
    while (q--) {
        int l, r;
        long long x;
        inpos(l), inpos(r), inpos(x);
        long long dif_1 = 0, dif_2 = 0;
        if (l > 1) {
            long long L_1 = sgt.get(1, 1, n, l - 1, l - 1);
            long long L_2 = sgt.get(1, 1, n, l, l);
            dif_1 = L_2 - L_1;
        }
        if (r < n) {
            long long R_1 = sgt.get(1, 1, n, r, r);
            long long R_2 = sgt.get(1, 1, n, r + 1, r + 1);
            dif_2 = R_2 - R_1;
        }
        sgt.update(1, 1, n, l, r, x);
        if (l > 1) {
            long long L_1 = sgt.get(1, 1, n, l - 1, l - 1);
            long long L_2 = sgt.get(1, 1, n, l, l);
            change(dif_1, L_2 - L_1);
        }
        if (r < n) {
            long long R_1 = sgt.get(1, 1, n, r, r);
            long long R_2 = sgt.get(1, 1, n, r + 1, r + 1);
            change(dif_2, R_2 - R_1);
        }
        answer();
    }

    return 0;
}