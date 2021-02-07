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

const int N = 15;

int h, w;
char a[N][N];
char b[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    auto get = [&]() -> void {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (a[i][j] == '.') continue;
                if (a[i + 1][j] == '.') {
                    if (a[i][j - 1] == '#' && a[i + 1][j - 1] == '.') continue;
                    ++ans;
                }
            }
        }
    };

    auto rotate = [&]() -> void {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                b[i][j] = a[i][j];
            }
        }
        for (int j = 1; j <= w; j++) {
            for (int i = h, k = 1; i >= 1; i--, k++) {
                a[j][k] = b[i][j];
            }
        }
        swap(h, w);
    };

    for (int it = 0; it < 4; it++) {
        get();
        rotate();
    }
    cout << ans << '\n';

    return 0;
}