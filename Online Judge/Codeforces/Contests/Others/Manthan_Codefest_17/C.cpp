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

const int M = 1e9 + 7;
const int N = 1e4 + 5;
const int K = 50;
const int prime = 31;

int n, m;
char s[N];
long long fact[N];
map<int, int> mp;

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * prime) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cin >> m;
    vector<string> prec(m);
    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        prec[i] = a;
        int len = a.size();
        for (int j = 0; j < len; j++) {
            a[j] = tolower(prec[i][len - j - 1]);
        }
        long long res = 0;
        for (int j = len - 1, k = 0; j >= 0; j--, k++) {
            res = (res + (long long) (a[j] - 'a' + 1) * fact[k]) % M;
        }
        mp[res] = i;
    }
    vector<int> dp(n + 1, -1);
    vector<int> par(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        long long res = 0;
        for (int j = i, k = 0; j >= max(1, i - K); j--, k++) {
            res = (res + (long long) (s[j - 1] - 'a' + 1) * fact[k]) % M;
            if (!mp.count(res)) continue;
            if (dp[j - 1] != -1) {
                dp[i] = mp[res];
                par[i] = j - 1;
                break;
            }
        }
    }
    deque<string> answer;
    int it = n;
    while (it > 0) {
        answer.emplace_front(prec[dp[it]]);
        it = par[it];
    }
    int len = answer.size();
    for (int i = 0; i < len; i++) {
        cout << answer[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}