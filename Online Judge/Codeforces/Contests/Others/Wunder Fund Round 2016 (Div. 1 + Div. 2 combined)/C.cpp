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

struct point {
    long long x, y;
    int id;
    bool operator<(const point& o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    };
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].id = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        point& a = v[i];
        point& b = v[(i + 1) % n];
        point& c = v[(i + 2) % n];
        if ((b.y - a.y) * (c.x - b.x) == (b.x - a.x) * (c.y - b.y)) continue;
        cout << a.id << ' ' << b.id << ' ' << c.id << '\n';
        return 0;
    }
    assert(false);

    return 0;
}