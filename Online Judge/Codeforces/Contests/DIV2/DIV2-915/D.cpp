#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 0; i < n; i++) {
        cin >> dq[i];
    }
    while (dq.back() != 0) {
        int x = dq.back();
        dq.pop_back();
        dq.emplace_front(x);
    }
    vector<int> b(2 * n);
    for (int i = 0; i < n; i++) {
        b[i] = dq[i];
        b[i + n] = dq[i];
    }
    vector<int> L(2 * n);
    {
        stack<int> st;
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && b[st.top()] >= b[i]) {
                st.pop();
            }
            L[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }
    }
    long long ans = n;
    vector<long long> dp(2 * n);
    for (int i = n; i + 1 < 2 * n; i++) {
        dp[i] = 1LL * (i - L[i]) * b[i] + dp[L[i]];
        long long cur = dp[i] + n;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}