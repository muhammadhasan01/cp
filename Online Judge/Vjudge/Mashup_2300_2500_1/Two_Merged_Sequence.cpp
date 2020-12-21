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
int a[N];
int ans[N];
vector<int> st[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (st[0].empty() || a[st[0].back()] < a[i]) {
            st[0].emplace_back(i);
            continue;
        }
        if (st[1].empty() || a[st[1].back()] > a[st[0].back()]) {
            st[1].emplace_back(st[0].back());
            st[0].pop_back();
            if (st[0].empty() || a[st[0].back()] < a[i]) {
                st[0].emplace_back(i);
                continue;
            }
            st[1].emplace_back(i);
            continue;
        }
        if (a[st[1].back()] <= a[i]) {
            cout << "NO" << '\n';
            return 0;
        }
        st[1].emplace_back(i);
    }
    for (int i = 0; i < 2; i++) {
        while (!st[i].empty()) {
            ans[st[i].back()] = i;
            st[i].pop_back();
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}