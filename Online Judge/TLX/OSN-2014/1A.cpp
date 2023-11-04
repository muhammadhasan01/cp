#include <bits/stdc++.h>

using namespace std;

double toRadian(double a) {
	return (a * acos(-1)) / 180;
}

double sinDegree(double a) {
    return sin(toRadian(a));
}

double cosDegree(double a) {
    return cos(toRadian(a));
}

const int D = 1800;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string ss;
    cin >> ss;
    int n;
    cin >> n;
    vector<vector<int>> speeds(D + 1);
    for (int i = 0; i < n; i++) { 
        int k, s;
        cin >> k >> s;
        speeds[s].emplace_back(k);
    }
    vector<int> dp(D + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= D; i++) {
        sort(speeds[i].rbegin(), speeds[i].rend());
        for (int k : speeds[i]) {
            bool changed = false;
            for (int j = D; j >= i; j--) {
                if (dp[j - i] != -1) {
                    int cur = max(k, dp[j - i]);
                    if (cur > dp[j]) {
                        dp[j] = cur;
                        changed = true;
                    }
                }
            }
            if (!changed) {
                break;
            }
        }
    }
    double ans = 0.0;
    for (int i = 1; i <= D; i++) {
        if (dp[i] == -1) {
            continue;
        }
        double deg = i * 1.0 / 10;
        ans = max(ans, (double) 9.8 * 2.0 * dp[i] * dp[i] * abs(sinDegree(deg) * cosDegree(deg)));
    }
    cout << fixed << setprecision(12) << ans << '\n';
    
    return 0;
}