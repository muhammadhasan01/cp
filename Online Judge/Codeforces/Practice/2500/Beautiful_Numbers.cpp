#include <bits/stdc++.h>

using namespace std;

const int DIGIT = 19;
const int LCM = 2520;
const int SUM = LCM;
const int ID_LCM = 50;

int tc;
int id[LCM + 5];
int p[DIGIT];
long long dp[DIGIT][ID_LCM][SUM + 5];
long long l, r;

void init() {
    memset(dp, -1, sizeof(dp));
    int cnt = 0;
    for (int i = 1; i <= LCM; i++) {
        if (LCM % i == 0) id[i] = ++cnt;
    }
}

long long DP(int pos, int lcm, int sum, bool limit) {
    if (pos == 0)
        return (sum % lcm == 0);
    if (!limit && dp[pos][id[lcm]][sum] != -1)
        return dp[pos][id[lcm]][sum];
    int maks = (limit ? p[pos] : 9);
    int cursum = 0, curlcm = lcm;
    long long res = 0;
    for (int i = 0; i <= maks; i++) {
        cursum = (sum * 10 + i) % LCM;
        if (i > 0) {
            curlcm = (lcm / __gcd(lcm, i)) * i;
        }
        res += DP(pos - 1, curlcm, cursum, (limit && i == maks));
    }
    if (!limit) dp[pos][id[lcm]][sum] = res;
    return res;
}

long long solve(long long x) {
    int sz = 0;
    while (x) {
        p[++sz] = x % 10;
        x /= 10;
    }
    return DP(sz, 1, 0, true);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    cin >> tc;
    while (tc--) {
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << '\n';
    }

    return 0;
}