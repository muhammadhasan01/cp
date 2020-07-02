#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n;
string s;
bitset<N> dp[N];
pair<int,int> p[N * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    s = '#' + s;
    int k = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) break;
            if (i == j) {
                dp[i][j] = 1;
            } else if (i + 1 == j) {
                dp[i][j] = (s[i] == s[j] ? 1 : 0);
            } else {
                dp[i][j] = (s[i] == s[j] ? dp[i + 1][j - 1] : 0);
            }
            if (dp[i][j] == 1) p[++k] = {i, j};
        }
    }

    sort(p + 1, p + 1 + k);
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        int l = 1, r = k, pos = k + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[mid].first > p[i].second) {
                r = mid - 1;
                pos = mid;
            } else {
                l = mid + 1;
            }
        }
        ans += (1LL) * (k - pos + 1);
    }
    cout << ans << '\n';

    return 0;
}
