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
    int a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    string str;
    cin >> str;
    map<char, int> mp;
    for (char cc : str) {
        if (cc == 'L') x--;
        if (cc == 'R') x++;
        if (cc == 'U') y++;
        if (cc == 'D') y--;
        mp[cc]++;
    }
    bool ok_x = false;
    if (x != a) {
        if (x < a) {
            ok_x = (mp['L'] >= a - x);
        } else if (x > a) {
            ok_x = (mp['R'] >= x - a);
        }
    } else if (x == a) ok_x = true;
    bool ok_y = false;
    if (y != b) {
        if (y < b) {
            ok_y = (mp['D'] >= b - y);
        } else if (y > b) {
            ok_y = (mp['U'] >= y - b);
        }
    } else if (y == b) {
        ok_y = true;
    }
    cout << (ok_x && ok_y ? "YES" : "NO") << '\n';
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