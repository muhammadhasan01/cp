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

const int N = 3e5 + 5;
const long long M = 998244353;

int n, k;
pair<int, int> p[N];
long long fact[N], invf[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = (fact[a] * invf[a - b]) % M;
    ret = (ret * invf[b]) % M;
    return ret;
}

void preprocess() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        invf[i] = modpow(fact[i], M - 2);
    }
    debug() << imie(C(5, 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess();
    cin >> n >> k;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        p[i] = make_pair(l, r);
        nums.emplace_back(l); nums.emplace_back(r);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int len = nums.size();
    auto getID = [&](int x) -> int {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    };
    vector<int> in(len + 5), out(len + 5);
    for (int i = 1; i <= n; i++) {
        p[i].first = getID(p[i].first);
        p[i].second = getID(p[i].second);
        in[p[i].first]++;
        out[p[i].second]++;
    }
    long long res = 0;
    int cursz = 0;
    for (int i = 1; i <= len; i++) {
        debug() << imie(i) imie(in[i]) imie(out[i]);
        for (int j = 0; j < in[i]; j++)
            res = (res + C(cursz++, k - 1)) % M;
        for (int j = 0; j < out[i]; j++)
            cursz--;
    }
    cout << res << '\n';

    return 0;
}