#include <bits/stdc++.h>
using namespace std;
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

const long long MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int BLOCK = 350;
const int NUM_BLOCK = N / BLOCK + 5;

int n, m, q;
int a[N];
bool not_prime[M];
unordered_map<int, int> mp_block[NUM_BLOCK], mp_val[M];

void init() {
    for (int i = 2; i < M; i++) {
        if (not_prime[i]) continue;
        for (int j = i; j < M; j += i) {
            not_prime[j] = 1;
            mp_val[j][i]++;
        }
    }
}

void merge(unordered_map<int, int>& x, unordered_map<int, int>& y, int z) {
    for (auto& e : y) {
        x[e.first] += z * e.second;
        if (x[e.first] == 0)
            x.erase(e.first);
    }
}

void build() {
    int len = 0;
    for (int i = 1; i <= n; i += BLOCK) {
        ++len;
        for (int j = i; j <= i + BLOCK - 1; j++) {
            merge(mp_block[len], mp_val[a[j]], 1);
        }
    }
}

void update(int x, int y) {
    int len = (x + BLOCK - 1) / BLOCK;
    merge(mp_block[len], mp_val[a[x]], -1);
    a[x] = y;
    merge(mp_block[len], mp_val[a[x]], 1);
}

unordered_map<int, int> get(int pos) {
    unordered_map<int, int> ret;
    if (pos == 0) return ret;
    int len = (pos + BLOCK - 1) / BLOCK;
    for (int i = 1; i < len; i++)
        merge(ret, mp_block[i], 1);
    for (int j = (len - 1) * BLOCK + 1; j <= pos; j++) {
        merge(ret, mp_val[a[j]], 1);
    }
    return ret;
}

long long modpow(long long x, long long y) {
    x %= MOD;
    long long ret = 1;
    while (y) {
        if (y & 1LL) ret = (ret * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ret;
}

long long query(int L, int R) {
    unordered_map<int, int> x = get(R);
    unordered_map<int, int> y = get(L - 1);
    merge(x, y, -1);
    long long ret = 1;
    for (auto& e : x) {
        if (e.second == 0) continue;
        long long cur = modpow(e.first, e.second - 1);
        cur = (cur * (e.first - 1)) % MOD;
        ret = (ret * cur) % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y;
            cin >> x >> y;
            update(x, y);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            if (l > r) swap(l, r);
            cout << query(l, r) << '\n';
        }
    }

    return 0;
}