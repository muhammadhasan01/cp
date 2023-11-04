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

const int INF = 1e9;
const int K = 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string R, C;
    cin >> R >> C;
    vector<vector<vector<int>>> res(K);
    vector<int> p(n, INF);
    for (int i = 0; i < K; i++) {
        p[i] = i;
    }
    do {
        int fst = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] != INF) {
                fst = p[i];
                break;
            }
        }
        res[fst].emplace_back(p);
    } while (next_permutation(p.begin(), p.end()));

    vector<pair<int, int>> taken;
    vector<vector<int>> ans(n, vector<int>(n));

    auto convert = [&](int x) -> char {
        if (x == INF) {
            return '.';
        }
        return char(int('A') + x);
    };

    function<bool(int)> ret = [&](int idx) {
        if (idx == n) {
            for (int i = 0; i < n; i++) {
                ans[i] = res[taken[i].first][taken[i].second];
            }
            string X = "";
            for (int j = 0; j < n; j++) {
                vector<int> cnt(K);
                bool first = false;
                for (int i = 0; i < n; i++) {
                    if (ans[i][j] == INF) {
                        continue;
                    }
                    if (!first) {
                        first = true;
                        X += convert(ans[i][j]);
                    }
                    cnt[ans[i][j]]++;
                }
                if (cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1) {
                    continue;
                }
                return false;
            }
            return X == C;
        }
        int pos = R[idx] - 'A';
        for (int i = 0; i < (int) res[pos].size(); i++) {
            taken.emplace_back(pos, i);
            if (ret(idx + 1)) {
                return true;
            }
            taken.pop_back();
        }
        return false;
    };

    if (ret(0)) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << convert(ans[i][j]);
            }
            cout << '\n';
        }
        return 0;
    }

    cout << "No" << '\n';
    
    return 0;
}