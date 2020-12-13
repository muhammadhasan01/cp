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

const int N = 305;

int n;
char s[N][N];

void solve() {
    cin >> n;
    vector<vector<int>> cnt = {{0, 0}, {0, 0}, {0, 0}};
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            int val = (i + j) % 3;
            if (s[i][j] == 'X') {
                cnt[val][0]++;
                k++;
            } else if (s[i][j] == 'O') {
                cnt[val][1]++;
                k++;
            }
        }
    }
    for (int d = 0; d < 3; d++) {
        for (int d2 = 0; d2 < 3; d2++) {
            if (d == d2) continue;
            if (cnt[d][0] + cnt[d2][1] > k / 3) continue;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int val = (i + j) % 3;
                    if (val== d && s[i][j] == 'X') {
                        s[i][j] = 'O';
                    } else if (val == d2 && s[i][j] == 'O') {
                        s[i][j] = 'X';
                    }
                    cout << s[i][j];
                }
                cout << '\n';
            }
            return;
        }
    }
    assert(false);
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