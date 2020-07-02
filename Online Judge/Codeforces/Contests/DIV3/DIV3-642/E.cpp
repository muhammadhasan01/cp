#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int tc;
int n, k;
char a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == '1') sum++; 
        }
        int ans = sum;
        for (int i = 1; i <= k; i++) {
            int cur = 0, res = 0;
            for (int j = i; j <= n; j += k) {
                if (a[j] == '1') {
                    ++cur;
                } else {
                    --cur;
                    if (cur < 0) cur = 0;
                }
                res = max(res, cur);
            }
            ans = min(ans, sum - res);
        }
        cout << ans << '\n';
    }

    return 0;
}