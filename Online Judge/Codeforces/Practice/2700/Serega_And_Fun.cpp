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

const int NMAX = 1e5 + 5;
const int BLOCK = 600;
const int NUM_BLOCK = NMAX / BLOCK + 5;
const int REP = 1000;

int n, q;
int a[NMAX], val[NUM_BLOCK][BLOCK + REP + 5];
int sz[NUM_BLOCK], num_block;
short cnt[NUM_BLOCK][NMAX];

void build() {
    for (int i = 1; i <= n; i += BLOCK) {
        ++num_block;
        for (int j = i; j <= min(n, i + BLOCK - 1); j++) {
            val[num_block][++sz[num_block]] = a[j];
            cnt[num_block][a[j]]++;
        }
    }
}

int erase(int idx) {
    int len = 0, ret = -1;
    for (int i = 1; i <= num_block; i++) {
        len += sz[i];
        if (len < idx) continue;
        int pos = sz[i] - (len - idx);
        cnt[i][val[i][pos]]--; ret = val[i][pos];
        for (int j = pos; j < sz[i]; j++) {
            val[i][j] = val[i][j + 1];
        }
        val[i][sz[i]] = 0; sz[i]--;
        break;
    }
    return ret;
}

void insert(int idx, int value) {
    int len = 0;
    for (int i = 1; i <= num_block; i++) {
        len += sz[i];
        if (len < idx) continue;
        int pos = sz[i] - (len - idx);
        cnt[i][value]++;
        for (int j = sz[i] + 1; j > pos; j--) {
            val[i][j] = val[i][j - 1];
        }
        val[i][pos] = value; sz[i]++;
        break;
    }
} 

int getFreq(int idx, int k) {
    int len = 0, ret = 0;
    for (int i = 1; i <= num_block; i++) {
        len += sz[i], ret += cnt[i][k];
        if (len < idx) continue;
        int pos = sz[i] - (len - idx);
        for (int j = pos + 1; j <= sz[i]; j++) {
            if (val[i][j] == k) ret--;
        }
        break;
    }
    return ret;
}

void rebuild() {
    int id = 0;
    for (int i = 1; i <= num_block; i++) {
        for (int j = 1; j <= sz[i]; j++) {
            a[++id] = val[i][j];
            cnt[i][a[id]] = 0;
        }
        sz[i] = 0;
    }
    num_block = 0;
    build();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int lastans = 0;
    auto decode = [&](int& x) -> void {
        x = ((x + lastans - 1) % n) + 1;
    };

    build();
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            decode(l), decode(r);
            if (l > r) swap(l, r);
            if (l == r) continue;
            int value = erase(r);
            insert(l, value);
        } else if (tp == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            decode(l), decode(r), decode(k);
            if (l > r) swap(l, r);
            lastans = getFreq(r, k) - getFreq(l - 1, k);
            cout << lastans << '\n';
        }
        if (i % REP == 0) rebuild();
    }
    
    return 0;
}