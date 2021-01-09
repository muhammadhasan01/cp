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

const int N = 1e3 + 5;
const int BOUND = 1e6;

int n;
int x[N], y[N];
int parity[2];
vector<int> a[2][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        x[i] += BOUND, y[i] += BOUND;
    }
    while (1) {
        vector<vector<int>> cnt(2, vector<int>(2));
        for (int i = 1; i <= n; i++) {
            cnt[(x[i] & 1)][(y[i] & 1)]++;
        }
        int cur = 0;
        int p = -1, q = -1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (cnt[i][j]) {
                    ++cur;
                    p = i, q = j;
                }
            }
        }
        if (cur > 1) break;
        assert(cur == 1);
        for (int i = 1; i <= n; i++) {
            x[i] = (x[i] - p) / 2;
            y[i] = (y[i] - q) / 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur_parity = (x[i] + y[i]) & 1;
        parity[cur_parity]++;
        a[(x[i] & 1)][(y[i] & 1)].emplace_back(i);
    }
    vector<int> ans;
    if (parity[0] && parity[1]) {
        for (int id : a[0][0])
            ans.emplace_back(id);
        for (int id : a[1][1])
            ans.emplace_back(id);
    } else if (parity[0]) {
        for (int id : a[0][0])
            ans.emplace_back(id);
    } else if (parity[1]) {
        for (int id : a[0][1])
            ans.emplace_back(id);
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}