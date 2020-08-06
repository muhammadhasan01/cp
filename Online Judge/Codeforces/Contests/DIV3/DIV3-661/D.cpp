#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int k = 0;
        stack<int> ones, zeros;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            if (x == '0') {
                if (ones.empty()) {
                    zeros.emplace(++k);
                    ans[i] = k;
                } else {
                    int cur = ones.top();
                    ones.pop();
                    ans[i] = cur;
                    zeros.emplace(cur);
                }
            } else if (x == '1') {
                if (zeros.empty()) {
                    ones.emplace(++k);
                    ans[i] = k;
                } else {
                    int cur = zeros.top();
                    zeros.pop();
                    ans[i] = cur;
                    ones.emplace(cur);
                }
            }
        }
        cout << k << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}