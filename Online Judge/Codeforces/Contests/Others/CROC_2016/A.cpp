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

string s[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }

    string x = "", y = "";

    for (int i = 0; i < 2; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 2; j++) {
                if (s[i][j] != 'X') x += s[i][j];
            }
        } else {
            for (int j = 1; j >= 0; j--) {
                if (s[i][j] != 'X') x += s[i][j];
            }
        }
    }
    for (int i = 2; i < 4; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 2; j++) {
                if (s[i][j] != 'X') y += s[i][j];
            }
        } else {
            for (int j = 1; j >= 0; j--) {
                if (s[i][j] != 'X') y += s[i][j];
            }
        }
    }
    x += x;
    for (int i = 0; i < 3; i++) {
        if (x.substr(i, 3) == y) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';

    return 0;
}