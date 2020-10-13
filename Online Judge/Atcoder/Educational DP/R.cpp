#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

using matrix = vector<vector<long long>>;

const long long M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; long long k;
    cin >> n >> k;
    matrix a(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    auto multiply = [&](const matrix& x, const matrix& y) -> matrix {
        matrix ret(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    long long cur = (x[i][k] * y[k][j]) % M;
                    ret[i][j] = (ret[i][j] + cur) % M;
                }
            }
        }
        return ret;
    };

    auto fastexpo = [&](matrix x, long long y) -> matrix {
        matrix ret(n, vector<long long>(n));
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        while (y > 0) {
            if (y & 1) ret = multiply(ret, x);
            y >>= 1;
            x = multiply(x, x);
        }
        return ret;
    };

    matrix result = fastexpo(a, k);
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = (answer + result[i][j]) % M;
        }
    }
    cout << answer << '\n';

    return 0;
}