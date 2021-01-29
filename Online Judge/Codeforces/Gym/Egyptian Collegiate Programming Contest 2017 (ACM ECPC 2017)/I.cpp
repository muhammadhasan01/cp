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

#define F first
#define S second
typedef pair<int, int> pii;

const int NUM = 2003, N = 203, Q = 10003;

int n, m, q;

struct BIT {
    vector<vector<int>> b;
    BIT(int n, int m) : b(n, vector<int>(m)) {}
    void add(int ii, int jj, int v) {
        for (int i = ii + 1; i <= n; i += i & -i)
            for (int j = jj + 1; j <= m; j += j & -j)
                b[i - 1][j - 1] += v;
    }
    int get(int ii, int jj) {
        int v = 0;
        for (int i = ii + 1; i; i -= i & -i)
            for (int j = jj + 1; j; j -= j & -j)
                v += b[i - 1][j - 1];
        return v;
    }
    int query(int si, int sj, int ei, int ej) {
        --si, --sj;
        return get(ei, ej) - get(ei, sj) - get(si, ej) + get(si, sj);

    }
} bit(0, 0);

int val[N][N];
int si[Q], sj[Q], ei[Q], ej[Q], k[Q];
int sortedQ[Q], answer[Q], curT = 0;
vector<pii> pos[NUM];

void PBS(int st, int en, int lf, int rt) {
    if (rt < lf) return;
    if (st == en) {
        for (int i = lf; i <= rt; ++i) {
            answer[sortedQ[i]] = st;
        }
        return;
    }

    int md = (st + en) / 2;

    while (curT > md) {
        for (pii &c : pos[curT])
            bit.add(c.F, c.S, -1);
        --curT;
    }
    while (curT < md) {
        ++curT;
        for (pii &c : pos[curT])
            bit.add(c.F, c.S, 1);
    }
    int pivot = partition(sortedQ + lf, sortedQ + rt + 1, [](int qi) {
        return bit.query(si[qi], sj[qi], ei[qi], ej[qi]) > k[qi];  // assume you've done your md loop
    }) - sortedQ;

    PBS(st, md, lf, pivot - 1);
    PBS(md + 1, en, pivot, rt);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("important.in", "rt", stdin);

    int nTests;
    scanf("%d", &nTests);
    for (int tid = 1; tid <= nTests; ++tid) {
        scanf("%d%d%d", &n, &m, &q);
        bit = BIT(n, m);
        int MAX = 0;
        int MIN = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &val[i][j]);
                MAX = max(MAX, val[i][j]);
                MIN = min(MIN, val[i][j]);
            }
        }
        for (int v = MIN; v <= MAX; ++v) {
            pos[v].clear();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pos[val[i][j]].emplace_back(i, j);
            }
        }
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d%d", si + i, sj + i, ei + i, ej + i);
            --si[i], --sj[i], --ei[i], --ej[i];
            k[i] = (ei[i] - si[i] + 1) * (ej[i] - sj[i] + 1) / 2;
            sortedQ[i] = i;
        }
        curT = MIN-1;
        PBS(MIN, MAX, 0, q - 1);

        printf("Case %d:\n", tid);
        for (int i = 0; i < q; ++i) {
            printf("%d\n", answer[i]);
        }
    }
}