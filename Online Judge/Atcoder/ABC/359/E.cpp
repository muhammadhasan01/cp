#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    } 
    vector<long long> dp(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            st.pop();
        }
        int j = st.empty() ? -1 : st.top();
        if (j == -1) {
            dp[i] = 1LL * (i + 1) * h[i] + 1;
        } else {
            dp[i] = 1LL * (i - j) * h[i] + dp[j];
        }
        st.emplace(i);
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " \n"[i == n - 1];
    }
    
    return 0;
}