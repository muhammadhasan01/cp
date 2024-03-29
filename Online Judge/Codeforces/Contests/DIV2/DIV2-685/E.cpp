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

const int N = (1 << 16) + 5;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int special = -1;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 2; i <= n; i++) {
        cout << "XOR " << 1 << ' ' << i << endl;
        cin >> a[i];
        if (special == -1 && mp.count(a[i])) {
            cout << "AND " << mp[a[i]] << ' ' << i << endl;
            cin >> special;
            special = (special ^ a[i]);
        } else {
            mp[a[i]] = i;
        }
    }
    if (special == -1) {
        special = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] == 1 || a[i] == n - 2) {
                cout << "AND 1 " << i << endl;
                int res; cin >> res;
                special = (special ^ res); 
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << (special ^ a[i]);
        if (i < n)
            cout << ' ';
        else
            cout << endl;
    }

    return 0;
}