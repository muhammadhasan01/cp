#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<long long> ans;
        long long cur = 1;
        ans.push_back(cur);
        n -= cur;
        while (n > 0) {
            long long l = cur, r = 2 * cur, res = cur;
            if (l <= n && n <= r) {
                ans.push_back(n);
                break;
            }
            while (l <= r) {
                long long mid = (l + r) >> 1;
                if (2 * mid <= n) {
                    l = mid + 1;
                    res = mid;
                } else {
                    r = mid - 1;
                }
            }
            n -= res;
            ans.push_back(res);
            cur = res;
        }
        int len = ans.size();
        cout << len - 1 << '\n';
        for (int i = 1; i < len; i++) {
            cout << ans[i] - ans[i - 1] << (i == len - 1 ? '\n' : ' ');
        }
    }
    
    return 0;
}