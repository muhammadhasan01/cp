#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k;
string s;
long long dp[N];
multiset<long long> mins, vals;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;
    mins.insert(0);
    vector<vector<long long>> del(n);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = i + 1 + dp[i + 1];
        if (i + k + 2 <= n) mins.erase(mins.find(dp[i + k + 2]));
        for (auto e : del[i]) vals.erase(vals.find(e));
        if (!vals.empty()) dp[i] = min(dp[i], *vals.begin());
        if (s[i] == '1') {
            long long val = (mins.empty() ? 0 : *mins.begin() + i + 1);
            dp[i] = min(dp[i], val);
            vals.insert(val);
            if (i - k - 1 >= 0) del[i - k - 1].push_back(val);
        }
        mins.insert(dp[i]);
    }
    cout << dp[0] << '\n';

    return 0;
}
