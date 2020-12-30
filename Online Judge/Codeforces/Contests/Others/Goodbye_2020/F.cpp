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

const int N = 5e5 + 5;
const long long M = 1e9 + 7;

int n, m;
int par[N];
set<int> st[N];
bool one[N];
int pos[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if ((int) st[pu].size() < (int) st[pv].size()) swap(pu, pv);
    for (int x : st[pv]) st[pu].emplace(x);
    par[pv] = pu;
    if (one[pv]) one[pu] = 1;
}

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int lastone = -1;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        bool take = true;
        vector<int> c(k);
        for (int j = 0; j < k; j++) {
            cin >> c[j];
            st[i].emplace(c[j]);
        }
        if (k == 1) {
            if (pos[c[0]] == 0) {
                pos[c[0]] = i;
                one[i] = 1;
            } else {
                int pi = fpar(pos[c[0]]);
                if (one[pi]) {
                    take = false;
                } else {
                    one[i] = 1;
                    merge(i, pi);
                }
            }
            if (take) {
                merge(i, lastone);
                lastone = i;
            }
        }
        if (k == 2) {
            for (int j = 0; j < 2; j++) {
                int x = c[j];
                if (pos[x] == 0) {
                    pos[x] = i;
                } else {
                    int pi = fpar(pos[x]);
                    int res = 0;
                    for (int e : c) {
                        if (st[pi].find(e) != st[pi].end()) {
                            ++res;
                        }
                    }
                    if (res == 2) {
                        take = false;
                        break;  
                    }
                    merge(i, pi);
                }
            }
        }
        if (take) {
            ans.emplace_back(i);
        }
    }
    int len = ans.size();
    cout << modpow(2, len) << ' ' << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}