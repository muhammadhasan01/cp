#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

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

const long long M = 1e9 + 7;
const int N = 4e4 + 5;
const int p = 103;

long long pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 1;
    for (int i = 1; i < N; i++) {
        pre[i] = (pre[i - 1] * p) % M;
    }

    while (1) {
        int need; cin >> need;
        if (need == 0) break;
        string s; cin >> s;
        int n = s.length();

        long long cur = 1;
        vector<long long> hash(n);
        for (int i = 0; i < n; i++) {
            if (i > 0) hash[i] = hash[i - 1];
            hash[i] = (hash[i] + ((1LL) * (s[i] - 'a' + 1) * cur) % M) % M;
            cur = (cur * p) % M;
        }

        auto get = [&](int x, int y) -> int {
            long long ret = 0;
            ret = hash[y] - (x > 0 ? hash[x - 1] : 0LL);
            ret = (ret % M + M) % M;
            ret = (ret * pre[n - y]) % M;
            return ret;
        };
        
        auto can = [&](int len) -> int {
            int table_size = max((n - len + 1) / 2, 100);
            vector<vector<pair<int, int>>> table(table_size);
            auto add = [&](int hash) -> int {
                int pos = hash % table_size;
                for (int i = 0; i < (int) table[pos].size(); i++) {
                    if (table[pos][i].first == hash)
                        return ++table[pos][i].second;
                }
                table[pos].emplace_back(hash, 1);
                return 1;
            };
            int pos = -1;
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j >= n) break;
                int times = add(get(i, j));
                if (times >= need) {
                    pos = i;
                }
            }
            return pos;
        };

        if (can(1) == -1) {
            cout << "none" << '\n';
            continue;
        }

        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid) != -1) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << " " << can(ans) << '\n';
    }

    return 0;
}