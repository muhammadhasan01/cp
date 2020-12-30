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

const int N = 5e5 + 5;
const long long M = 1e9 + 7;
const int K = 62;

int n;
long long a[N];
int cnt[K];

void init() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            bool b = (a[i] & (1LL << j));
            if (b) cnt[j]++;
        }
    }
}

long long getValue(const vector<long long>& v) {
    long long res = 0;
    int len = v.size();
    for (int i = 0; i < len; i++) {
        long long cur = (1LL << i) % M;
        cur = (cur * v[i]) % M;
        res = (res + cur) % M;
    }
    return res;
}

long long handleAND(int pos) {
    vector<long long> v(K);
    for (int j = 0; j < K; j++) {
        bool b = (a[pos] & (1LL << j));
        if (b) {
            v[j] = cnt[j];
        }
    }
    return getValue(v);
}

long long handleOR(int pos) {
    vector<long long> v(K);
    for (int j = 0; j < K; j++) {
        bool b = (a[pos] & (1LL << j));
        if (b) {
            v[j] = n;
        } else {
            v[j] = cnt[j];
        }
    }
    return getValue(v);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init();
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long AND = handleAND(i);
        long long OR = handleOR(i);
        long long res = (AND * OR) % M;
        ans = (ans + res) % M;
    }
    cout << ans << '\n';
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