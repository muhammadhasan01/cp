#include <bits/stdc++.h>

using namespace std;
using plv = pair<long long, vector<int>>;

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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        v[i].resize(len);
        for (int& x : v[i]) {
            cin >> x;
        }
    }
    map<vector<int>, long long> dp;
    map<vector<int>, bool> done;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        vector<int> cur(n);
        for (int j = 0; j < n; j++) {
            cin >> cur[j];
            cur[j]--;
        }
        dp[cur] = -1;
    }
    auto get_v = [&](vector<int>& x) -> long long {
        if (dp.count(x)) {
            return dp[x];
        }
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            ret += v[i][x[i]];
        }
        return dp[x] = ret;
    };
    vector<int> init(n);
    for (int i = 0; i < n; i++) {
        init[i] = (int) v[i].size() - 1;
    }
    priority_queue<plv> pq;
    pq.emplace(0LL, init);
    while (true) {
        auto [val, vec] = pq.top();
        pq.pop();
        debug() << imie(val) imie(vec);
        val = -val;
        if (get_v(vec) != -1) {
            for (int i = 0; i < n; i++) {
                cout << (vec[i] + 1) << " \n"[i == n - 1];
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vec[i] - 1 < 0) {
                continue;
            }
            long long dif = v[i][vec[i]] - v[i][vec[i] - 1];
            vec[i]--;
            if (done.count(vec)) {
                vec[i]++;
                continue;
            }
            done[vec] = true;
            pq.emplace(-(val + dif), vec);
            vec[i]++;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}