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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (m & 1) {
        cout << "YES" << '\n';
        cout << 1 << ' ';
        for (int k = 0; k < m; k++) {
            cout << (k % 2 == 0 ? 2 : 1) << " \n"[k == m - 1];
        }
        return;
    }
    vector<vector<int>> v(n, vector<int>(2, -1));
    vector<vector<int>> w(n, vector<int>(2, -1));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == a[j][i]) {
                cout << "YES" << '\n';
                cout << i + 1 << ' ';
                for (int k = 0; k < m; k++) {
                    cout << (k % 2 == 0 ? j : i) + 1 << " \n"[k == m - 1];
                }
                return;
            }
            int x = a[i][j] - 'a';
            int y = a[j][i] - 'a';
            v[i][x] = j;
            w[i][y] = j;
            v[j][y] = i;
            w[j][x] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i][0] == -1 || v[i][1] == -1) continue;
        if (w[i][0] == -1 || w[i][1] == -1) continue;
        cout << "YES" << '\n';
        int p = i, q = v[i][0], r = v[i][1];
        if (m % 4 != 0) swap(p, q);
        cout << p + 1 << ' ';
        for (int j = 0; j < m / 2; j++) {
            cout << (j % 2 == 0 ? q : p) + 1 << ' ';
        }
        if (m % 4 != 0) swap(p, q);
        for (int j = 0; j < m / 2; j++) {
            cout << (j % 2 == 0 ? r : p) + 1 << " \n"[i == m / 2 - 1];
        }
        return;
    }
    cout << "NO" << '\n';
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