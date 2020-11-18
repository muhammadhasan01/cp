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

const int N = 1e2 + 5;

int n, m;
char a[N][N];
char b[N][N];

int change(int xx, int yy, int x, int y) {
    int ret = 0;
    for (int i = xx; i <= xx + 1; i++) {
        for (int j = yy; j <= yy + 1; j++) {
            if (i == x && j == y) {
                ret += (b[i][j] == '1');
                continue;   
            }
            b[i][j] = (b[i][j] == '1' ? '0' : '1');
            ret += (b[i][j] == '1');
        }
    }
    return ret;
}

void add(vector<pair<int, int>>& v, int xx, int yy, int x, int y) {
    for (int i = xx; i <= xx + 1; i++) {
        for (int j = yy; j <= yy + 1; j++) {
            if (i == x && j == y) continue;
            a[i][j] = (a[i][j] == '1' ? '0' : '1');
            v.emplace_back(i, j);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == n - 1) {
                vector<pair<int, int>> cur = {{i, j}, {i + 1, j}, {i, j + 1}, {i + 1, j + 1}};
                vector<int> rep(4);
                iota(rep.begin(), rep.end(), 0);
                do {
                    for (auto& e : cur) {
                        b[e.first][e.second] = a[e.first][e.second];
                    }
                    int pos = -1;
                    for (int it = 0; it < 4; it++) {
                        int id = rep[it];
                        if (change(i, j, cur[id].first, cur[id].second) == 0) {
                            pos = it;
                            break;
                        }
                    }
                    if (pos != -1) {
                        for (int it = 0; it <= pos; it++) {
                            int id = rep[it];
                            add(v, i, j, cur[id].first, cur[id].second);
                        }
                        break;
                    }
                } while (next_permutation(rep.begin(), rep.end()));
                if (j == m - 1) break;
            } else if (a[i][j] == '1') {
                if (j == m) {
                    add(v, i, j - 1, i, j - 1);
                } else {
                    add(v, i, j, i + 1, j + 1);
                }
            }
        }
    }
    int len = v.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            assert(a[i][j] == '0');
        }
    }
    cout << len / 3 << '\n';
    for (int i = 0; i < len; i++) {
        cout << v[i].first << ' ' << v[i].second << (i % 3 == 2 ? '\n' : ' ');
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