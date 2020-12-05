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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> res(2); // result for non working day and working day
    res[0] = 0, res[1] = n;
    vector<set<pair<int, int>>> st(2);
    st[1].insert(make_pair(1, n));

    auto upd = [&](int k, int add) -> void {
        res[k] += add;
        res[1 - k] -= add;
    };

    auto solve = [&](int l, int r, int k) -> void {
        {
            int o = 1 - k; // other
            pair<int, int> cur = make_pair(l, l);
            // left part, that is less than l
            auto lp = st[o].lower_bound(cur);
            if (lp != st[o].begin()) {
                --lp;
                pair<int, int> val = *lp;
                if (val.second > r) {
                    upd(k, r - l + 1);
                    st[o].emplace(val.first, l - 1);
                    st[o].emplace(r + 1, val.second);
                    st[o].erase(val);
                } else if (val.second >= l) {
                    upd(k, val.second - l + 1);
                    st[o].emplace(val.first, l - 1);
                    st[o].erase(val);
                }
            }

            while (1) {
                auto it = st[o].lower_bound(cur);
                if (it == st[o].end() || it->first > r) break;
                pair<int, int> val = *it;
                cur = make_pair(val.second + 1, val.second + 1);
                if (val.second <= r) {
                    upd(k, val.second - val.first + 1);
                    st[o].erase(val);
                } else {
                    upd(k, r - val.first + 1);
                    st[o].emplace(r + 1, val.second);
                    st[o].erase(val);
                }
            }
        }
        
        {
            pair<int, int> cur = make_pair(l, l);
            // left part, that is less than l
            auto lp = st[k].lower_bound(cur);
            if (lp != st[k].begin()) {
                --lp;
                pair<int, int> val = *lp;
                if (val.second > r) {
                    st[k].emplace(val.first, l - 1);
                    st[k].emplace(r + 1, val.second);
                    st[k].erase(val);
                } else if (val.second >= l) {
                    st[k].emplace(val.first, l - 1);
                    st[k].erase(val);
                }
            }

            while (1) {
                auto it = st[k].lower_bound(cur);
                if (it == st[k].end() || it->first > r) break;
                pair<int, int> val = *it;
                cur = make_pair(val.second + 1, val.second + 1);
                if (val.second <= r) {
                    st[k].erase(val);
                } else {
                    st[k].emplace(r + 1, val.second);
                    st[k].erase(val);
                }
            }
        }

        st[k].emplace(l, r);
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        solve(l, r, --k);
        debug() << imie(st);
        debug() << imie(res);
        cout << res[1] << '\n';
    }

    
    return 0;
}