#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
const long long INF = 1e18;

int n;
int a[N];
long long dp[2][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        v[i - 1] = a[i];
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int len = v.size();
    for (int j = 0; j < len; j++) {
        dp[1][j] = abs(a[1] - v[j]);
        if (j > 0) {
            dp[1][j] = min(dp[1][j], dp[1][j - 1]);
        }
    
    for (int it = 2; it <= n; it++) {
        int now = (it & 1);
        int bfr = !(it & 1);
        for (int j = 0; j < len; j++) {
            dp[now][j] = abs(a[it] - v[j]) + dp[bfr][j];
            if (j > 0) {
                dp[now][j] = min(dp[now][j], dp[now][j - 1]);
            }
        }
    }
    cout << dp[(n & 1)][len - 1] << '\n';

    return 0;
}