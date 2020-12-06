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

const int N = 1e5 + 5;

int n;
bool done[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> ret;
    for (int i = 3; i <= n; i += 2) {
        if (done[i]) continue;
        vector<int> cur;
        for (int j = i + i; j <= n; j += i) {
            if (done[j]) continue;
            cur.emplace_back(j);
        }
        int len = cur.size();
        if (len == 0) continue;
        if (len % 2 == 0)
            cur[0] = i;
        else
            cur.emplace_back(i);
        for (int x : cur) {
            done[x] = 1;
            ret.emplace_back(x);
        }
    }
    for (int i = 2; i <= n; i += 2) {
        if (done[i]) continue;
        ret.emplace_back(i);
    }
    int len = ret.size();
    if (len & 1) {
        ret.pop_back();
        --len;
    }
    cout << len / 2 << '\n';
    for (int i = 0; i < len; i += 2) {
        cout << ret[i] << ' ' << ret[i + 1] << '\n';
    }

    return 0;
}