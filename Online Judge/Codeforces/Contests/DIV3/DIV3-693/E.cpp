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

struct st {
    int h, w, id;
    bool operator<(const st& o) {
        return h < o.h;
    };
};

void solve() {
    int n;
    cin >> n;
    vector<st> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].h >> v[i].w;
        v[i].id = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n, -1);
    vector<vector<pair<int, int>>> pending(n);
    int last = -1;
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (v[mid].h < v[i].w) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (i > 0 && v[i - 1].h < v[i].h) last = i - 1;
        if (last != -1) pending[last].emplace_back(v[i].id, v[i].w);
        if (at != -1)
            pending[at].emplace_back(v[i].id, v[i].h);
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.emplace(v[i].w, v[i].id);
        for (auto& e : pending[i]) {
            auto it = st.lower_bound(make_pair(e.second, -1));
            if (it != st.begin()) {
                it--;
                ans[e.first] = it->second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) ans[i]++;
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}