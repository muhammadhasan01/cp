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

vector<vector<long long>> v = {{0, 0, 0},
    {0, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, 2},
    {0, -1, 2},
    {0, 0, 2},
    {0, 1, 2},
    {1, 1, 2},
    {-2, -2, 3},
    {7, 10, -11},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, 2, 2},
    {-511, -1609, 1626},
    {1, 2, 2},
    {-1, -2, 3},
    {0, -2, 3},
    {1, -2, 3},
    {-11, -14, 16},
    {-1, -1, -1},
    {-1, -1, -1},
    {-2901096694, -15550555555, 15584139827},
    {-1, -1, 3},
    {0, -1, 3},
    {0, 0, 3},
    {0, 1, 3},
    {1, 1, 3},
    {-283059965, -2218888517, 2220422932},
    {-1, -1, -1},
    {-1, -1, -1},
    {8866128975287528, -8778405442862239, -2736111468807040},
    {-1, 2, 3},
    {0, 2, 3},
    {1, 2, 3},
    {0, -3, 4},
    {1, -3, 4},
    {117367, 134476, -159380},
    {-1, -1, -1},
    {-1, -1, -1},
    {-80538738812075974, 80435758145817515, 12602123297335631},
    {2, 2, 3},
    {-5, -7, 8},
    {2, -3, 4},
    {-2, 3, 3},
    {6, 7, -8},
    {-23, -26, 31},
    {-1, -1, -1}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (v[n][0] == -1 && v[n][1] == -1 && v[n][2] == -1) {
        cout << 0 << '\n';
    } else {
        for (int i = 0; i < 3; i++) {
            cout << v[n][i] << (i == 2 ? '\n' : ' ');
        }
    }

    return 0;
}