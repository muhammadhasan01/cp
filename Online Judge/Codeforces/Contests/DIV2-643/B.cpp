#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int a[N], dp[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i - a[i] + 1 >= 1) {
                dp[i] = max(dp[i], 1 + dp[i - a[i]]);
            } 
        }
        cout << *max_element(dp + 1, dp + 1 + n) << '\n';
    }
    
    return 0;
}