#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/478/submission/62200855

const int M = 1e9 + 7;
const int N = 2e5 + 5;
int r, g;
int dp[N], pref[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> g;
    int res = r + g;
    int le = 0, ri = 1000, n = -1;
    while (le <= ri) {
        int mid = (le + ri) >> 1;
        if ((mid * (mid + 1)) / 2  <= res) {
            le = mid + 1;
            n = mid;
        }  else {
            ri = mid - 1;
        }
    }
    // base case
    dp[0] = 1;
    /*
		dp[i][j] = number of towers of height i taking j red blocks in total
		We have 2 possibilities,
		either we make ith row with red or we don't.
		so transitions are
		dp[i][j] = dp[i-1][j]  + dp[i-1][j-i];

		We can see that ith state if only dependent on i-1,
		so two arrays representing ith and (i-1)th state works.

		PS: This dp is similar to that of subset sum problem.
	*/
    for (int i = 1; i <= n; i++) {
        if (i > r) break;
        for (int j = 0; j <= r; j++) pref[j] = dp[j];
        for (int j = 0; j <= r; j++) {
            if (j - i >= 0) {
                dp[j] += pref[j - i];
                dp[j] %= M;
            }
        }
    }
    long long ans = 0;
    int st = n * (n + 1) / 2 - g;
    // 	the number of red blocks can range from start to r
    for (int i = st; i <= r; i++) {
        ans += (1LL) * dp[i];
        ans %= M;
    }
    cout << (ans % M + M) % M << '\n';

    return 0;
}
