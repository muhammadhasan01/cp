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

const int K = 26;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n > k) {
        cout << -1 << '\n';
        return;
    }
    vector<int> w(K);
    int len = 0;
    {
        int it = K - 1;
        while (it >= 0) {
            int cur = (1 << it);
            if (k >= cur) {
                k -= cur;
                w[it]++, len++;
            } else {
                it--;
            }
        }
    }
    if (len > n) {
        cout << -1 << '\n';
        return;
    }
    while (len < n) {
        for (int i = K - 1; i >= 1; i--) {
            if (w[i] > 0) {
                len++;
                w[i]--;
                w[i - 1] += 2;
                break;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < w[i]; j++) {
            cout << char(int('a') + i);
        }
    }
    cout << '\n';
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