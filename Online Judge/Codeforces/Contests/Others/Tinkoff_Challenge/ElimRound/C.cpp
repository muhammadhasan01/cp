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

#define double long double

const int N = 1e5 + 5;
const double INF = 2e9;

struct item {
    double vx, vy, x, y;
};

int n;
double x_1, x_2, y_1, y_2;
item p[N];
double tim[N];

double getTim(int pos) {
    item& cur = p[pos];
    double ret = 0;
    for (int rep = 0; rep < 2; rep++) {
        if (cur.vx > 0) {
            if (cur.x < x_1)
                ret = max(ret, ((x_1 - cur.x) / cur.vx));
            else if (cur.x > x_2)
                ret = INF;
        } else if (cur.vx == 0) {
            if (cur.x < x_1 || cur.x > x_2)
                ret = INF;
        } else {
            if (cur.x > x_2)
                ret = max(ret, ((x_2 - cur.x) / cur.vx));
            else if (cur.x < x_1)
                ret = INF;
        }
        swap(x_1, y_1); swap(x_2, y_2);
        swap(cur.x, cur.y); swap(cur.vx, cur.vy);
    }
    debug() << imie(pos) imie(ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    double resTim = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].vx >> p[i].vy;
        resTim = max(resTim, getTim(i));
    }
    debug() << imie(resTim);
    for (int i = 1; i <= n; i++) {
        p[i].x += (resTim * p[i].vx);
        p[i].y += (resTim * p[i].vy);
        debug() << imie(i) imie(p[i].x) imie(p[i].y);
        if (p[i].x < x_1 || p[i].x > x_2 || p[i].y < y_1 || p[i].y > y_2) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << fixed << setprecision(16) << resTim << '\n';

    return 0;
}