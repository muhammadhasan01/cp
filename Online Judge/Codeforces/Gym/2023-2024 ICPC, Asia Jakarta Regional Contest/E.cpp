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
    
    int n;
    cin >> n;
    vector<int> pos(2 * n + 1);
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<bool> done(2 * n + 1);
    deque<int> X;
    for (int x = 2 * n; x >= 1; x--) {
        int p = pos[x];
        if (done[p]) {
            continue;
        }
        int cur = 0;
        for (int i = p; i <= 2 * n; i++) {
            if (done[i]) {
                break;
            }
            ++cur;
            done[i] = true;
        }
        X.emplace_front(cur);
    }
    int len = (int) X.size();
    vector<vector<bool>> dp(len + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = true;
            } else if (j >= X[i - 1] && dp[i - 1][j - X[i - 1]]) {
                dp[i][j] = true;
            }
        }
    }
    if (!dp[len][n]) {
        cout << -1 << '\n';
        return 0;
    }
    int i = len, j = n;
    deque<int> A, B;
    int cur = 2 * n;
    while (i > 0) {
        if (dp[i - 1][j]) {
            for (int rep = 0; rep < X[i - 1]; rep++) {
                B.emplace_front(a[cur--]);
            }
            i--;
        } else {
            for (int rep = 0; rep < X[i - 1]; rep++) {
                A.emplace_front(a[cur--]);
            }
            j -= X[i - 1];
            i--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << B[i] << " \n"[i == n - 1];
    }
    
    return 0;
}