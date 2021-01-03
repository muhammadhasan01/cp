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



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("adjustment.in", "r", stdin); 
    freopen("adjustment.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    long long ans = (1LL) * (n + 1) * (n + 2) / 2 - 1;
    long long ans_row = ans, ans_col = ans;
    int num_row = n, num_col = n;
    vector<bool> row(n + 1), col(n + 1);
    while (q--) {
        char CC;
        cin >> CC;
        if (CC == 'R') {
            int r;
            cin >> r;
            if (row[r]) {
                cout << 0 << '\n';
                continue;
            }
            row[r] = true;
            cout << (ans_row + (1LL) * num_col * (r - 1)) << '\n';
            ans_col -= (r + 1);
            num_row--;
        } else if (CC == 'C') {
            int c;
            cin >> c;
            if (col[c]) {
                cout << 0 << '\n';
                continue;
            }
            col[c] = true;
            cout << (ans_col + (1LL) * num_row * (c - 1)) << '\n';
            ans_row -= (c + 1);
            num_col--;
        }
    }

    return 0;
}