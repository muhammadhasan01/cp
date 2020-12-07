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

const int N = 2e5 + 5;

int n;
long long a[N];
long long pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    auto evaluate = [&](int pos, int k) -> long double {
        long double ret = pre[n] - pre[n - k];
        ret += (pre[pos] - pre[pos - k - 1]);
        ret /= (2 * k + 1);
        ret -= a[pos];
        return ret;
    };

    int pos = -1, k = -1;
    long double ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        int l = 1, r = min(i - 1, n - i);
        while (r - l >= 3) {
            int p1 = l + (r - l) / 3;
            int p2 = r - (r - l) / 3;
            if (evaluate(i, p1) < evaluate(i, p2)) {
                l = p1;
            } else {
                r = p2;
            }
        }
        for (int j = l; j <= r; j++) {
            long double cur = evaluate(i, j);
            if (cur > ans) {
                ans = cur;
                pos = i, k = j;
            }
        }
    }
    if (ans == 0) {
        cout << 1 << '\n';
        cout << a[1] << '\n';
        return 0;
    }
    cout << 2 * k + 1 << '\n';
    for (int i = pos - k; i <= pos; i++) {
        cout << a[i] << ' ';
    }
    for (int i = n - k + 1; i <= n; i++) {
        cout << a[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}