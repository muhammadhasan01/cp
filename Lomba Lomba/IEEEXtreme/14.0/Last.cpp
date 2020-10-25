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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int p = 31;
    const int M = 1e9 + 7;
    const vector<pair<int, int>> euy = {make_pair(int('A'), int('Z')), make_pair(int('0'), int('9'))};

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int len = v[0].size();
    vector<long long> pre(len + 5);
    pre[0] = 1;
    for (int i = 1; i < len; i++) {
        pre[i] = ((1LL) * pre[i - 1] * p) % M;
    }
    debug() << imie(pre);
    unordered_map<int, int> mp;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        vector<int> pref(len);
        {
            long long cur = 0;
            for (int j = 0; j < len; j++) {
                cur = (cur + (1LL) * int(v[i][j]) * pre[j]) % M;
                pref[j] = cur;
            }
        }
        for (int j = 0; j < len; j++) {
            if (v[i][j] == '-') continue;
            int curval = int(v[i][j]);
            for (int rep = 0; rep < 2; rep++) {
                for (int x = euy[rep].first; x <= euy[rep].second; x++) {
                    if (curval == x) continue;
                    long long cur = ((j == 0 ? 0 : pref[j - 1]) + (1LL) * x * pre[j]) % M;
                    long long ruc = pref[n - 1] - pref[j];
                    ruc = (ruc % M + M) % M;
                    cur = (cur + ruc) % M;
                    answer   += mp[cur];
                }
            }
        }
        mp[pref[n - 1]]++;
    }
    cout << answer << '\n';

    return 0;
}